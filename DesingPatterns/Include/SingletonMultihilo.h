#pragma once
#include "Preriquisites.h"
#include <mutex>

class
	SingletonMultihilo {
private:
//El Constructor es privado para evitar instancias externas de la clase
	SingletonMultihilo() = default;
public: 
	static SingletonMultihilo& getInstance() {
		//Verificar si la instancia ya existe antesa de ser bloqueada 
		if (m_instance == nullptr) {
			lock_guard<mutex> lock(m_mutexInstance);
			if (m_instance == nullptr) {
				m_instance = new SingletonMultihilo;
			}
		}
		return *m_instance;
	}

	void 
		setValue(int _value) {
		m_value = _value;
	}

	int 
		getvalue() {
		return m_value;
	}

private: 
	static SingletonMultihilo* m_instance;
	static mutex m_mutexInstance;
	int m_value;
};

