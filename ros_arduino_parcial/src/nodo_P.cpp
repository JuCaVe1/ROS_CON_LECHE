#include "ros/ros.h" 	//Añadir librerias o paquetes (ros)
#include "std_msgs/String.h" 	//Añadir librerias o paquetes (para variable string)
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes (para variables enteras)
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes (para variables flotantes)
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes (para utilizar caracteres)
#include "std_msgs/Int32MultiArray.h"	//no lo usé pero bueno
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes (variable booleana)
#include <sstream> 	//Añadir librerias o paquetes (para imprimir)
//#include <sstream> 	//Añadir librerias o paquetes


 std_msgs::Int32 Entero_Recibido;
void Int(const std_msgs::Int32::ConstPtr& Entero) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Entero_Recibido.data=Entero->data;
	ROS_INFO("El Entero Es: [%d]", Entero->data); //Es la manera que se usa para imprimir
}
 std_msgs::Float64 Flotante_Recibido;
void Float(const std_msgs::Float64::ConstPtr& Flotante) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Flotante_Recibido.data=Flotante->data;
	ROS_INFO("El Flotante Es: [%f]", Flotante->data); //Es la manera que se usa para imprimir
}
 std_msgs::Int32 Booleano_Recibido;
void Bool(const std_msgs::Int32::ConstPtr& Booleano) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Booleano_Recibido.data=Booleano->data;
	ROS_INFO("El Cambio Es Este: [%d]", Booleano->data); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "nodo_P"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;
	ros::Subscriber Pub_entero = n.subscribe("Entero", 2, Int); //Por medio de esta funcion se le dice a ROS que quiere recibir mensaje sobre un topic especifico, Los mensajes se pasan a una 											función de devolución de llamada, aquí llamado chatterCallback. subscribe() devuelve un objeto Suscriptor que usted debe 											conservar 											hasta que desee darse de 											baja el segundo parametro de la funcion
                                                                   		//es el tamaño del mensaje en cola.
	ros::Subscriber Pub_flotante = n.subscribe("Flotante", 2, Float);
	ros::Subscriber Pub_booleano = n.subscribe("Booleano", 2, Bool);


   	ros::Publisher Enviar_Entero = n.advertise<std_msgs::Int32>("Nodo_1_Entero", 2); //la funcion advertise es la que dice lo que ROS quiere publicar dado el nombre de un topic, Por medio del nodo maestro de 												ROS
                                                                           		//mantiene registrando de quien esta publicando y quien se esta suscribiendo
	ros::Publisher Enviar_Flotante = n.advertise<std_msgs::Float64>("Nodo_2_Flotante", 2);
	ros::Publisher Enviar_Booleano = n.advertise<std_msgs::Int32>("Nodo_3_Booleano", 2);



 ros::Rate loop_rate(30); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;
  while (ros::ok()) 
 {

 //ROS_INFO("El Entero Es: [%d]", Entero_Recibido);
 //ROS_INFO("El De Publicar: %d", Entero_Recibido);
 Enviar_Entero.publish(Entero_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado. 
 Enviar_Flotante.publish(Flotante_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.
 Enviar_Booleano.publish(Booleano_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.


 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}








