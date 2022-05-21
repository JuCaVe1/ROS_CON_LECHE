#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes


 //std_msgs::Int32 Entero_Recibido;
void Int(const std_msgs::String::ConstPtr& Entero_N4_TI) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	//Entero_Recibido.data=Entero->data;
	ROS_INFO("Sensor1: [%s]", Entero_N4_TI->data.c_str()); //Es la manera que se usa para imprimir
}
 //std_msgs::Float64 Flotante_Recibido;
void Float(const std_msgs::String::ConstPtr& Flotante_N5_TI) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	//Flotante_Recibido.data=Flotante->data;
	ROS_INFO("Sensor2: [%s]", Flotante_N5_TI->data.c_str()); //Es la manera que se usa para imprimir
}
// std_msgs::Bool Booleano_Recibido;
void Bool(const std_msgs::String::ConstPtr& Booleano_N6_TI) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	//Booleano_Recibido.data=Booleano->data;
	ROS_INFO("State: [%s]", Booleano_N6_TI->data.c_str()); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_S_Final"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;
	ros::Subscriber Pub_entero = n.subscribe("Nodo_4_Enviar_Entero_TI", 2, Int); 
			
                                                                   		//es el tamaño del mensaje en cola.
	ros::Subscriber Pub_flotante = n.subscribe("Nodo_5_Enviar_Flotante_TI", 2, Float);
	ros::Subscriber Pub_booleano = n.subscribe("Nodo_6_Enviar_Booleano_TI", 2, Bool);


   	//ros::Publisher Enviar_Entero = n.advertise<std_msgs::Int32>("Nodo_1_Entero", 2); //la funcion advertise es la que dice lo que ROS quiere publicar dado el nombre de un topic, Por medio del nodo maestro de 												ROS
                                                                           		//mantiene registrando de quien esta publicando y quien se esta suscribiendo
	//ros::Publisher Enviar_Flotante = n.advertise<std_msgs::Float64>("Nodo_2_Flotante", 2);
	//ros::Publisher Enviar_Booleano = n.advertise<std_msgs::Bool>("Nodo_3_Booleano", 2);



 ros::Rate loop_rate(0.5); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;
  while (ros::ok()) 
 {

 //ROS_INFO("El Entero Es: [%d]", Entero_Recibido);
 //ROS_INFO("El De Publicar: %d", Entero_Recibido);
 //Enviar_Entero.publish(Entero_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado. 
 //Enviar_Flotante.publish(Flotante_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.
 //Enviar_Booleano.publish(Booleano_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.


 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}
