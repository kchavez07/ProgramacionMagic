#pragma once
#include "Preriquisites.h"
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <cstdlib>


queue<int> buffer;
mutex mtx;
condition_variable cv;
const int bufferSize = 5;

void productor() {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return buffer.size() < bufferSize; });

        int dato = rand() % 100;
        buffer.push(dato);

        cout << "Productor: Producido " << dato << endl;

        lock.unlock();
        cv.notify_all();
    }
}

void consumidor(int id) {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return !buffer.empty(); });

        int dato = buffer.front();
        buffer.pop();

        cout << "Consumidor " << id << ": Consumio " << dato << endl;

        lock.unlock();
        cv.notify_all();
    }
}