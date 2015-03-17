#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>
#include <vector>


#include "config.h"

#define _WIN32_WINNT 0x0602
#define ASIO_STANDALONE
#include "asio.hpp"


std::mutex global_stream_lock;
void WorkerThread (std::shared_ptr <asio::io_service > io_service) {
	
	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] thread start\n";
	global_stream_lock.unlock ();

	io_service->run ();

	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] thread stop\n";
	global_stream_lock.unlock ();
}

void Dispatch (int x) {
	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] "
		<< __FUNCTION__ << " x = " << x << std::endl;
	global_stream_lock.unlock ();
}

void Post (int x) {
	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] "
		<< __FUNCTION__ << " x = " << x << std::endl;
	global_stream_lock.unlock ();
}

void Run3 (std::shared_ptr<asio::io_service> io_service) {
	for (int i = 0; i < 3; ++i) {
		io_service->dispatch (std::bind (&Dispatch, i * 2));
		io_service->post (std::bind (&Post, i * 2 + 1));
		std::this_thread::sleep_for(std::chrono::milliseconds (1000));
	}
}

unsigned fib (unsigned n) {
	if (n <= 1) { return 1; }
	
	std::this_thread::sleep_for (std::chrono::milliseconds (1000));
	
	return fib (n - 1) + fib (n - 2);
}

void CalcFib (unsigned n) {
	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] Calculating fib(" << n << ")\n";
	global_stream_lock.unlock ();

	unsigned f = fib (n);

	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id () << "] fib(" << n << ") is " << f << "\n";
	global_stream_lock.unlock ();
}

int main () {

	//TODO: concurrently bind USB ports to motor objects
	//TODO: create motor class
	
	std::shared_ptr<asio::io_service > io_service (new asio::io_service);
	std::shared_ptr<asio::io_service::work > work (new asio::io_service::work (*io_service));
	
	global_stream_lock.lock ();
	std::cout << "[" << std::this_thread::get_id ()
		<< "] The program will exit when all work has finished." << std::endl;
	global_stream_lock.unlock ();

	std::vector<std::thread> worker_threads(2);
	for (auto &thread : worker_threads) {
		thread = std::thread( [&](){
				WorkerThread(io_service); 
		});
	}
	
	io_service->post([](){ CalcFib(5); });
	io_service->post([](){ CalcFib(4); });
	io_service->post([](){ CalcFib(3); });

	work.reset ();
	for (auto &thread : worker_threads) {
		thread.join();
	}


	std::cout << "Does this display?" << std::endl;

	return 0;
}