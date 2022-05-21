#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include "std_msgs/Int32.h" 	//Añadir librerias o paquetes
#include "std_msgs/Bool.h" 	//Añadir librerias o paquetes

void chatterCallback(const std_msgs::Int32::ConstPtr& str_msg) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario

{
	ROS_INFO("I heard: [%d]", str_msg->data);  //Es la manera que se usa para imprimir
}

int main(int argc, char **argv)  //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{

   ros::init(argc, argv, "subscriber");  //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	ros::Subscriber sub = n.subscribe("chatter", 2, chatterCallback); //Por medio de esta funcion se le dice a ROS que quiere recibir mensaje sobre un topic especifico, Los mensajes se pasan a una función de devolución de llamada, aquí llamado chatterCallback. subscribe() devuelve un objeto Suscriptor que usted debe conservar hasta que desee darse de baja el segundo parametro de la funcion
                                                                   //es el tamaño del mensaje en cola.
	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}
