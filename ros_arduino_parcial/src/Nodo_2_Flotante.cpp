#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes



 std_msgs::Float64 Flotante_N2;
void Float(const std_msgs::Float64::ConstPtr& Flotante_Recibido) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Flotante_N2.data=Flotante_Recibido->data;
	ROS_INFO("El Flotante Recibido Es: [%f]", Flotante_Recibido->data); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_2_Flotante"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;

	ros::Subscriber Sub_flotante = n.subscribe("Nodo_2_Flotante", 2, Float);

	ros::Publisher Enviar_Flotante_TE = n.advertise<std_msgs::String>("Nodo_2_Enviar_Flotante_TE", 2);


 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;

 std_msgs::String Flotante_N2_TE;
 Flotante_N2_TE.data = "";

  while (ros::ok()) 
 {

	if (Flotante_N2.data<1.62)
		Flotante_N2_TE.data = "Lento";
	else if (Flotante_N2.data<2.99)
		Flotante_N2_TE.data = "Normal";
	else 
		Flotante_N2_TE.data = "Rapido";

	Enviar_Flotante_TE.publish(Flotante_N2_TE);


 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}
