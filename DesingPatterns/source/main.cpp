#include "Preriquisites.h"
#include "singleton.h"
#include "RegistroActividad.h"
#include "FactoryMethod.h"
#include "FactoryPractica.h"
#include "Builder.h"
#include "BuilderPractica.h"
#include "Prototype.h"
#include "PrototypePractica .h"
#include "Adapter.h"
#include "AdapterPractica.h"
#include "Decorator.h"
#include "DecoratorPractica.h"
#include "Composite.h"
#include "CompositePractica.h"
#include "Proxy.h"
#include "ProxyPractica.h"
#include "Bridge.h"
#include "ChainofResponsability.h"
#include "ChainR_Practica.h"
#include "TemplateMethod.h"
#include "TemplatePractica.h"

//Threads
#include <thread>
#include <mutex>

Singleton* Singleton::instance = nullptr;
mutex mtx;

// Función que simula la ejecución de un hilo.
// La función toma un argumento 'id' que representa el identificador del hilo.
void Hilo(int id) {
	for (int i = 0; i < 5; i++) {
		mtx.lock(); //Se bloquea el mutex 
		cout<< "Hilo: " << id << "esta trabajando." << endl; 
		mtx.unlock(); //Se desbloquear el mutex cuando el lock sale de alcanze 
	}
}


//Singleton
Singleton* Singleton::instance = nullptr;

int main() {
	// Obtener la instancia del Singleton
	Singleton* s1 = Singleton::getInstance();
	s1->setValue(42);

	// Obtener otra instancia (será la misma)
	Singleton* s2 = Singleton::getInstance();
	cout << "Dato singleton 2: " << s2->getValue() << endl;

	// Imprimir el valor de la instancia original (s1)
	cout << "Dato de la instancia: " << s1->getValue() << endl;

	//RegistroActividad
	int main(); 
	{
		// Obtener la instancia del RegistroActividad (Singleton)
		RegistroActividad* a1 = RegistroActividad::getInstancia2();

		// Agregar un log
		a1->setLog("Buenos días, bienvenido al mundo espacial");

		// Obtener otra instancia (debería ser la misma)
		RegistroActividad* a2 = RegistroActividad::getInstancia2();

		// Agregar otro log
		a2->setLog("Padrisimo");

		// Mostrar los logs
		cout << "Ingresando al mundo virtual..." << endl;

		for (const auto& chats : a2->getLog()) {
			cout << chats << endl;
		}

		// Liberar memoria 
		delete a1;

		return 0;
	}

	// Factory Method
	int main(); 
	{
		// Crear una fábrica concreta
		FMFabricaConcreta* fabrica = new FMFabricaConcreta();

		// Crear productos usando la fábrica
		FMProducto* producto = fabrica->crearProducto();
		FMProducto* chettos = fabrica->crearPapas();
		FMProducto* pepsi = fabrica->crearRefresco();

		// Realizar operaciones en los productos
		cout << "Operación en producto genérico:" << endl;
		producto->operacion();

		cout << "\nOperación en Chettos:" << endl;
		dynamic_cast<FmChettos*>(chettos)->registrar("Chettos Extra", 100.0f, 25.0f);
		chettos->operacion();

		cout << "\nOperación en Pepsi Black:" << endl;
		dynamic_cast<FMPepsiBlack*>(pepsi)->registrar("Pepsi Black XL", 500.0f, 35.0f);
		pepsi->operacion();

		// Liberar memoria
		delete fabrica;
		delete producto;
		delete chettos;
		delete pepsi;

		return 0;
	}


	//FactoryPractica 
	int main(); {
		// Instancia de FactoriaCoches
		FactoriaVehiculos* fabricaCoches = new FactoriaCoches();

		// Método crearVehiculo() para crear un coche
		Vehiculo* miCoche = fabricaCoches->crearVehiculo();

		// Mostrar la descripción del coche
		miCoche->descripcion();

		// Liberar la memoria
		delete miCoche;
		delete fabricaCoches;

		return 0;
	}


	//Builder 
	int main(); {
		// Crear un constructor concreto
		BuilderConcreto* builder = new BuilderConcreto();

		// Crear un director con el constructor
		Director* director = new Director(builder);

		// Construir el producto
		director->construir();

		// Obtener el producto construido
		BProducto* producto = builder->obtenerProducto();

		// Mostrar el producto
		producto->mostrar();

		// Liberar memoria
		delete builder;
		delete director;
		delete producto;

		return 0;
	}


	//BuilderPractica(Pizzas) 
	int main();
	{
		// Crear una pizza hawaiana
		ConstructorPizzaHawaiana constructorHawaiano;
		constructorHawaiano.construirMasa();
		constructorHawaiano.construirSalsa();
		constructorHawaiano.construirQueso();
		constructorHawaiano.construirIngredientes();

		Pizza pizzaHawaiana = constructorHawaiano.obtenerPizza();
		cout << "Pizza Hawaiana:" << endl;
		pizzaHawaiana.mostrarPizza();

		// Crear una pizza vegetariana
		ConstructorPizzaVegetariana constructorVegetariano;
		constructorVegetariano.construirMasa();
		constructorVegetariano.construirSalsa();
		constructorVegetariano.construirQueso();
		constructorVegetariano.construirIngredientes();

		Pizza pizzaVegetariana = constructorVegetariano.obtenerPizza();
		cout << "\nPizza Vegetariana:" << endl;
		pizzaVegetariana.mostrarPizza();

		return 0;
	}

	// Prototype 
	int main(); {
		// Crear un prototipo concreto
		PrototypeConcreto* prototipo = new PrototypeConcreto();

		// Configurar y mostrar el prototipo original
		prototipo->configurar("Original");
		prototipo->mostrar();

		// Clonar el prototipo
		Prototype* copia = prototipo->clonar();

		// Configurar y mostrar la copia
		copia->configurar("Copia");
		copia->mostrar();

		// Liberar memoria
		delete prototipo;
		delete copia;

		return 0;
	}


	// Prototype Practica
	int main(); {
		// Crear un prototipo de documento de texto
		DocumentoPrototype* prototipoTexto = new DocumentoTexto();
		prototipoTexto->configurar("Texto de ejemplo");

		// Crear un prototipo de documento de imagen
		DocumentoPrototype* prototipoImagen = new DocumentoImagen();
		prototipoImagen->configurar("imagen.png");

		// Clonar los prototipos para obtener copias
		DocumentoPrototype* copiaTexto = prototipoTexto->clonar();
		DocumentoPrototype* copiaImagen = prototipoImagen->clonar();

		// Modificar las copias
		copiaTexto->configurar("Texto modificado");
		copiaImagen->configurar("nueva_imagen.png");

		// Restaurar los prototipos originales
		prototipoTexto->configurar("Texto original");
		prototipoImagen->configurar("imagen_original.png");

		// Mostrar los documentos
		cout << "Documento original de texto:" << endl;
		prototipoTexto->clonar()->mostrar();
		cout << "\nCopia modificada de texto:" << endl;
		copiaTexto->mostrar();

		cout << "\nDocumento original de imagen:" << endl;
		prototipoImagen->clonar()->mostrar();
		cout << "\nCopia modificada de imagen:" << endl;
		copiaImagen->mostrar();

		// Liberar memoria
		delete prototipoTexto;
		delete prototipoImagen;
		delete copiaTexto;
		delete copiaImagen;

		return 0;
	}


	//Adapter
	int main(); {
		// Crear una instancia de la interfaz vieja
		InterfazVieja* objetoViejo = new InterfazVieja();

		// Crear una instancia del adaptador conectando la interfaz vieja con la nueva
		InterfazNueva* objetoNuevo = new Adapter(objetoViejo);

		// Llamar al método de la interfaz nueva a través del adaptador
		objetoNuevo->MetodoNuevo();

		// Liberar memoria
		delete objetoViejo;
		delete objetoNuevo;

		return 0;
	}


	//Adapter Practica
	int main(); {
		// Crear instancias de Circulo y Cuadrado
		Circulo* circulo = new Circulo();
		Cuadrado* cuadrado = new Cuadrado();

		// Crear adaptadores para ambas figuras
		Dibujable* adaptadorCirculo = new CirculoAdapter(circulo);
		Dibujable* adaptadorCuadrado = new CuadradoAdapter(cuadrado);

		// Dibujar utilizando los adaptadores
		adaptadorCirculo->dibujar();
		adaptadorCuadrado->dibujar();

		// Liberar memoria
		delete circulo;
		delete cuadrado;
		delete adaptadorCirculo;
		delete adaptadorCuadrado;

		return 0;
	}


	//Decorator
	int main(); {
		// Crear un objeto concreto
		ComponenteConcreto* obj = new ComponenteConcreto();

		// Crear decoradores
		DecoratorConcretoA* DecoradorA = new DecoratorConcretoA(obj);
		DecoratorConcretoB* DecoratorB = new DecoratorConcretoB(DecoradorA);

		// Llamar a la operación en cada nivel
		obj->operacion();           // Operación del componente concreto
		DecoradorA->operacion();    // Operación del componente concreto + Decorator A
		DecoratorB->operacion();    // Operación del componente concreto + Decorator A + Decorator B

		// Liberar memoria
		delete obj;
		delete DecoradorA;
		delete DecoratorB;

		return 0;
	}


	//DecoratorPractica
	int main(); {
		// Crear una instancia de la cafetería
		Cafeteria* cafeteria = new Cafeteria();

		// Crear instancias de condimentos (Leche y Azúcar)
		Leche* cafeConLeche = new Leche(cafeteria);
		Azucar* cafeConAzucar = new Azucar(cafeteria);

		// Preparar café sin condimentos
		cafeteria->prepararCafe();

		// Decorar con leche y mostrar
		cafeConLeche->decorar();

		// Decorar con azúcar y mostrar
		cafeConAzucar->decorar();

		// Liberar memoria
		delete cafeteria;
		delete cafeConLeche;
		delete cafeConAzucar;

		return 0;
	}


	//Composite
	int main(); {
		// Crear hojas
		Leaf* leaf1 = new Leaf();
		Leaf* leaf2 = new Leaf();

		// Crear un componente compuesto
		Compuesto* compuesto = new Compuesto();
		compuesto->agregarLeaf(leaf1);
		compuesto->agregarLeaf(leaf2);

		// Realizar la operación en el componente compuesto
		compuesto->operacion();

		// Liberar memoria
		delete leaf1;
		delete leaf2;
		delete compuesto;

		return 0;
	}


	//CompositePractica
	int main(); {
		// Crear dos instancias de Archivo y una de SistemaCarpeta
		Archivo* archivol = new Archivo();
		Archivo* archivo2 = new Archivo();
		SistemaCarpeta* carpeta = new SistemaCarpeta();

		// Agregar los archivos a la carpeta
		carpeta->agregarSistema(archivol);
		carpeta->agregarSistema(archivo2);

		// Mostrar información de la carpeta y sus sistemas contenidos
		carpeta->mostrarInfo();

		// Liberar memoria
		delete archivol;
		delete archivo2;
		delete carpeta;

		return 0;
	}

	//Proxy 
	int main(); {
		// Crear una instancia de Proxy
		Proxy proxy;

		// Llamar a la operación del proxy
		proxy.operacion();

		// Llamar nuevamente a la operación del proxy, que redirige al sujeto real existente
		proxy.operacion();

		return 0;
	}

	// ProxyPractica
	int main(); {
		ProxyImagen proxy;

		// Se llama al método mostrar del proxy, que internamente redirige a la operación del sujeto real.
		proxy.mostrar();
		proxy.mostrar();

		return 0;
	}

	// Bridge
	int main(); {
		// Crear instancias de implementaciones concretas
		ImplementacionConcretaA impA;
		ImplementacionConcretaB impB;

		// Crear instancias de abstracciones refinadas asociadas a implementaciones concretas
		AbstraccionRefinada ARA(&impA);
		AbstraccionRefinada ARB(&impB);

		// Llamar a la operación de las abstracciones refinadas
		ARA.operacion();
		ARB.operacion();

		return 0;
	}

	// Chain of Responsibility 
	int main(); {
		// Crear instancias de manejadores concretos y establecer la cadena
		ManejadorConcretoC handleC(nullptr);
		ManejadorConcretoB handleB(&handleC);
		ManejadorConcretoA handleA(&handleB);

		// Probar diferentes solicitudes en la cadena
		handleA.manejarSolicitud(50);
		handleA.manejarSolicitud(5);
		handleA.manejarSolicitud(20);

		return 0;
	}

	//ChainR Practica 
	int main(); {
		ManejadorDirectorGeneral directorGeneral(nullptr);
		ManejadorGerente gerente(&directorGeneral);
		ManejadorDirectivo directivo(&gerente);

		Solicitud solicitud1(800);
		Solicitud solicitud2(3500);
		Solicitud solicitud3(10000);

		directivo.manejar(solicitud1);
		directivo.manejar(solicitud2);
		directivo.manejar(solicitud3);

		return 0;
	}

	//Template Method 
	    Juego* juego1 = new Ajedrez();
	    Juego* juego2 = new Monopoly();

	    juego1->jugar();
	    juego2->jugar();

	    delete juego1;
	    delete juego2;

	return 0;
   }

    // Template Practica 
   int main() {
		   // Crear instancias de las subclases y probar el patrón Template Method.
		   RefrigeradorSamsung samsung;
		   RefrigeradorLG lg;

		   // Inicializar, encender y apagar cada refrigerador.
		   samsung.inicializar();
		   samsung.encender();
		   samsung.apagar();

		   lg.inicializar();
		   lg.encender();
		   lg.apagar();

		   return 0;
	   }

   //Mutex
	// Crear tres hilos, cada uno ejecutando la función Hilo con un identificador único.
   thread hilo1(Hilo, 1);
   thread hilo2(Hilo, 2);
   thread hilo3(Hilo, 3);

   // Esperar a que cada hilo complete su ejecución antes de continuar.
   hilo1.join();
   hilo2.join();
   hilo3.join();
  
   // Mensajes de ejecución entre hilos después de que todos los hilos hayan terminado.
   cout << "\n-- Ejecucion 1 entre hilos" << endl;
   cout << "\n-- Ejecucion 2 entre hilos" << endl;
   cout << "\n-- Ejecucion 3 entre hilos" << endl;

   return 0;