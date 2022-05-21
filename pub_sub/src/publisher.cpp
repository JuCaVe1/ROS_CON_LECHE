#include "ros/ros.h" 	//Añadir librerias o paquetes
#include "std_msgs/String.h" 	//Añadir librerias o paquetes
#include <sstream> 	//Añadir librerias o paquetes

int main(int argc, char **argv)
{
 ros::init(argc, argv, "publisher"); //Se llama una de las versiones de ROS, el tercer argumento es el nombre del nodo

 ros::NodeHandle n; //Es para la comunicación de ROS, el primero contruye e inicializa el nodo y el ultimo lo destruye y cierra el nodo

 ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_1", 2); //la funcion advertise es la que dice lo que ROS quiere publicar dado el nombre de un topic
 
 ros::Rate loop_rate(10);  //Permite especificar una frecuencia en la que le gustaría hacer un bucle. En este caso esta funcionando a 10Hz.

 int count = 0;
 
 while (ros::ok()) 
 {
 std_msgs::String msg;  //Un conteo de cuantos mensajes hemos enviado. Esto se usa para crear una cadena única para cada mensaje.
 std::stringstream ss;  //Transmitimos un mensaje en ROS utilizando una clase adaptada al mensaje, generalmente generada a partir de un archivo msg.
 ss << "hello world " << count; 
 //ss << "hola ";
 msg.data = ss.str();
 
 ROS_INFO("%s", msg.data.c_str());    //Es la manera que se usa para imprimir

 chatter_pub.publish(msg);

 ros::spinOnce();     //se usa en caso de que se agregara una suscripción y no tuviera ros::spinOnce() aquí, sus devoluciones de llamada nunca serían llamadas.
 loop_rate.sleep();  // Mantendrá un registro de cuánto tiempo ha pasado desde la última llamada a Rate::sleep(), y dormirá durante la cantidad de tiempo correcta.
 ++count;
 }
return 0;
}
