#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Float64.h" 	//Añadir librerias o paquetes
#include "std_msgs/Char.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes
//#include <sstream> 	//Añadir librerias o paquetes



 std_msgs::Int32 Booleano_N3;
void Bool(const std_msgs::Int32::ConstPtr& Booleano_Recibido) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	Booleano_N3.data=Booleano_Recibido->data;
	ROS_INFO("El Nuevo Entero Recibido Es: [%d]", Booleano_Recibido->data); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "Nodo_3_Booleano"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	//int16[10] Int;

	ros::Subscriber Sub_booleano = n.subscribe("Nodo_3_Booleano", 2, Bool);


	ros::Publisher Enviar_Booleano_TE = n.advertise<std_msgs::String>("Nodo_3_Enviar_Booleano_TE", 2);


 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;

 std_msgs::String Booleano_N3_TE;
 Booleano_N3_TE.data = "";

  while (ros::ok()) 
 {

	if (Booleano_N3.data==0)
		Booleano_N3_TE.data = "Apagado";
	else if (Booleano_N3.data==1)
		Booleano_N3_TE.data = "Encendido";


	Enviar_Booleano_TE.publish(Booleano_N3_TE);


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
