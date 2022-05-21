#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes



 std_msgs::String Flotante_N5;
void Float(const std_msgs::String::ConstPtr& Flotante_N2_TE) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Flotante_N5.data=Flotante_N2_TE->data;
	ROS_INFO("El Flotante Recibido Es: [%s]", Flotante_N2_TE->data.c_str()); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_5_Flotante_TI"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo

	ros::Subscriber Sub_flotante = n.subscribe("Nodo_2_Enviar_Flotante_TE", 2, Float);

	ros::Publisher Enviar_Flotante_TI = n.advertise<std_msgs::String>("Nodo_5_Enviar_Flotante_TI", 2);


 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;

 std_msgs::String Flotante_N5_TI;
 Flotante_N5_TI.data = "";

  while (ros::ok()) 
 {

	if (Flotante_N5.data=="Lento")
		Flotante_N5_TI.data = "Slow";
	else if (Flotante_N5.data=="Normal")
		Flotante_N5_TI.data = "Normal";
	else 
		Flotante_N5_TI.data = "Speed";

	Enviar_Flotante_TI.publish(Flotante_N5_TI);


 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}
