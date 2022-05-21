#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes


 std_msgs::String Entero_N4;
void Int(const std_msgs::String::ConstPtr& Entero_N1_TE) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Entero_N4.data=Entero_N1_TE->data.c_str();
	ROS_INFO("El Entero Recibido Es: [%s]", Entero_N1_TE->data.c_str()); //Es la manera que se usa para imprimir
}


int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_4_Entero_TI"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;
	ros::Subscriber Sub_entero = n.subscribe("Nodo_1_Enviar_Entero_TE", 2, Int); 


	ros::Publisher Enviar_Entero_TI = n.advertise<std_msgs::String>("Nodo_4_Enviar_Entero_TI", 2);


 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;
 std_msgs::String Entero_N4_TI;
 Entero_N4_TI.data = "";

  while (ros::ok()) 
 {
	if (Entero_N4.data=="Frio")
		Entero_N4_TI.data = "Cold";
	else if (Entero_N4.data=="Tibio")
		Entero_N4_TI.data = "Warm";
	else 
		Entero_N4_TI.data = "Hot";

	Enviar_Entero_TI.publish(Entero_N4_TI);


		


// Enviar_Entero.publish(Entero_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado. 
// Enviar_Flotante.publish(Flotante_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.
// Enviar_Booleano.publish(Booleano_Recibido); //Ahora transmitimos el mensaje a cualquiera que esté conectado.


 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}
