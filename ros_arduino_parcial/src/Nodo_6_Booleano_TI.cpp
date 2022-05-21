#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes



 std_msgs::String Booleano_N6;
void Bool(const std_msgs::String::ConstPtr& Booleano_N3_TE) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Booleano_N6.data=Booleano_N3_TE->data;
	ROS_INFO("El Nuevo Entero Recibido Es: [%s]", Booleano_N3_TE->data.c_str()); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_6_Booleano_TI"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;

	ros::Subscriber Sub_booleano = n.subscribe("Nodo_3_Enviar_Booleano_TE", 2, Bool);


	ros::Publisher Enviar_Booleano_TI = n.advertise<std_msgs::String>("Nodo_6_Enviar_Booleano_TI", 2);


 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;

 std_msgs::String Booleano_N6_TI;
 Booleano_N6_TI.data = "";

  while (ros::ok()) 
 {

	if (Booleano_N6.data=="Apagado")
		Booleano_N6_TI.data = "Off";
	else if (Booleano_N6.data=="Encendido")
		Booleano_N6_TI.data = "On";


	Enviar_Booleano_TI.publish(Booleano_N6_TI);


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
