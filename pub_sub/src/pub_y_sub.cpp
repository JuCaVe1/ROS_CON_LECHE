#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes



void chatterCallback(const std_msgs::String::ConstPtr& msg) //Esta funcion devuelve el mensaje que recibe y es pasado por un impulso shared_ptr esto quiere decir que puede almacenarlo si es necesario
{
	ROS_INFO("I heard: [%s]", msg->data.c_str()); //Es la manera que se usa para imprimir
}

int main(int argc, char **argv) //La funcion init necesita de los argumentos argc y argv para que funcione cualquier argumento de ROS y reasignaciones de nombres que se hacen en las lineas de comandos
{
   ros::init(argc, argv, "pub_y_sub"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo
	ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo
	ros::Subscriber sub = n.subscribe("topic_1", 2, chatterCallback); //Por medio de esta funcion se le dice a ROS que quiere recibir mensaje sobre un topic especifico, Los mensajes se pasan a una función de devolución de llamada, aquí llamado chatterCallback. subscribe() devuelve un objeto Suscriptor que usted debe conservar hasta que desee darse de baja el segundo parametro de la funcion
                                                                   //es el tamaño del mensaje en cola.
   ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_2", 2); //la funcion advertise es la que dice lo que ROS quiere publicar dado el nombre de un topic, Por medio del nodo maestro de ROS
                                                                           //mantiene registrando de quien esta publicando y quien se esta suscribiendo

 ros::Rate loop_rate(10); //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz. 
  int count = 0;
  while (ros::ok()) 
 {
 std_msgs::String h; //Un conteo de cuantos mensajes hemos enviado. Esto se usa para crear una cadena única para cada mensaje.

 std::stringstream ss; //Transmitimos un mensaje en ROS utilizando una clase adaptada al mensaje, generalmente generada a partir de un archivo msg.
 ss << "hello world " << count;
 h.data = ss.str();
 
 //ROS_INFO("%s", h.data.c_str());

 chatter_pub.publish(h); //Ahora transmitimos el mensaje a cualquiera que esté conectado. 

 ros::spinOnce();  //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }

	ros::spin(); //ros::spin() entra en un bucle, llamando a las devoluciones de llamada de mensajes lo más rápido posible.
	return 0;
}








