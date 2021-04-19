// Proyecto 3.0 pagina.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
/* Auto: Luis Andres Ortiz Sanchez*/

#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

/*Prototipos*/

queue <string> separar(string palabras, char separador);// separar el archivo cvs por medio de un separador

queue <string> lectura(string archivo);// lee y almacena el archivo en una cola

queue <string>divpag(bool control,queue <string> cola, char separador, int sum);// separa las paginas en un parametro establecido


void crearpag(int tan,bool control,int con, queue<string> archivo, char separador);// crea paginas individuales y entrelaza

string crearpagdet(int tan,bool control,int cos,int con, string archivo, char separador);// crea paginas detalladas





int main()
{
	queue <string> cola;// variable de la cola donde se almacena toda la base de datos

	int conto = 0;
	int max;
	bool control = false;
	cola=lectura("tv_shows.csv");

	cola.pop();

	max = cola.size();


	while (!cola.empty())
	{
		max = cola.size();


		cola=divpag(control,cola,',',conto);
		conto++;

		
	}


	return 0;
}

queue <string> separar(string palabras, char separador)
{
	queue <string> datos;

	int a = 0;
	int b = 0;
	while (a != palabras.npos)
	{
		datos.push(palabras.substr(a + (a != 0), (b = palabras.find(separador, a + 1)) - a - (a != 0)));
		a = b;

	}

	return datos;

}

queue <string> lectura(string archivo)

{
	queue<string> values;

	ifstream file(archivo);
	
	if (file.is_open()) {
		string lineas;
		while (getline(file, lineas)) {


			values.push(lineas);


		} 

			file.close();
		}

	return values;

	}

void crearpag(int tan,bool control, int con, queue<string> archivo, char separador)
{
	int con2 = con + 1;

	int con3 = con - 1;
	
	string valor = to_string(con);

	string valor2 = to_string(con2);
	
	string valor3 = to_string(con3);

	string lista="index"+valor+".html";

	string lista2 = "index" + valor2 + ".html";

	string lista3 = "index" + valor3 + ".html";

	string devolver;

	ofstream file(lista);
	file << "<!DOCTYPE html>";
	file << "<html lang=\"es\">";
	file << "<head><meta charset=\"utf - 8 \"/><title> Proyecto Algoritmos</title></head>";
	file << "<style type =\"text/css\">table,th,td{border:1px solid black;border-collapse: collapse;height: 10px;width:10px;}th,td{ padding:15px;}nav{text-align: center;padding: 30px 50px 0 0;}nav>a {margin-left: 100px;margin-right: 100px;}</style>";
	file << "<body>";
	file << "<center><h1>Pagina de listas</h1></center>";
	file << "<table style=\"width:100%\">";

	int pal = archivo.size();

	file << "<tr><th>#</th><th>Title</th><th>Year</th><th>Age</th><th>IMDb</th><th>Rotten Tomatoes</th><th>Netflix</th><th>Hulu</th><th>Prime Video</th><th>Disney+</th><th>type</th><tr>";
	

		for (int j = 0; j < pal; j++)
		{
			string w = archivo.front();

			devolver=crearpagdet(tan,control,j,con,w, separador);

			queue<string> values = separar(w, separador);

			int n = values.size();

			file << "<tr>";
			for (int i = 0; i < n; i++)
			{


				file << "<td>" << values.front() << "</td>";

				values.pop();

			}
		
			file << "<td>" <<  "<a href=" << devolver << "><img src=\"Detalle.png\" width=\"90%\" heigth=\"90%\"></a>" << "</td>";
			

			file << "</tr>";

			archivo.pop();

		}

		file << "</table>";
		file << "<nav>";
		if (con3!=-1)
		{
			file << "<a href=" << lista3 << "><img src=\"Atras.png\" width=\"5%\" heigth=\"5%\"></a>";
		}
		if (control!=true)
		{
			file << "<a href=" << lista2 << "><img src=\"Siguiente.png\" width=\"5%\" heigth=\"5%\"></a>";
		}
		file << "</nav>";
		file << "</body></html>";
		file.close();


		cout << "Pagina creada con exito" << endl;
		
}

queue <string> divpag(bool control,queue <string> cola, char separador, int sum)
{
	int n = cola.size();
	int tan = 12;


	queue <string> divi;

	if (n>12)
	{
		for (int i = 0; i < 12; i++)
		{
			string c;
			c = cola.front();
			divi.push(c);
			cola.pop();
		}
		
		crearpag(tan,control,sum,divi,separador);
		
	}
	if (n<12)
	{
		int x = cola.size();


		for (int i = 0; i < x; i++)
		{
			string c;
			c = cola.front();
			divi.push(c);
			cola.pop();

			if (i==x-1)
			{
				control = true;
			}
		}
		
		crearpag(x,control,sum, divi, separador);

	}

	return cola;
}

string crearpagdet(int tan ,bool control,int cos ,int con, string archivo, char separador)

{
	
	if (tan <12)
	{
		control = false;

	}



	int ant=con;
	int ant2=cos-1;

	if (ant2==-1 and ant !=0)
	{
		ant = con - 1;
		ant2 = 11;
	}

	else
	{
		ant = con;
		ant2 = cos - 1;
	}



	int dps=con;
	int dps2=cos+1;

	if (cos == 11 )
	{
		dps = con + 1;
		dps2 = 0;
	}

	else
	{
		dps = con;
		dps2 = cos + 1;
	}

	string antes = to_string(ant);
	string antes2 = to_string(ant2);

	string desp = to_string(dps);
	string desp2 = to_string(dps2);


	string valor = to_string(con);
	string valor2 = to_string(cos);

	string lista = "Detalles" + valor+ valor2 + ".html";

	string lista1 = "Detalles" + antes+ antes2 + ".html";
	string lista2 = "Detalles" + desp+ desp2 + ".html";


	ofstream file(lista);
	file << "<!DOCTYPE html>";
	file << "<html lang=\"es\">";
	file << "<head><meta charset=\"utf - 8 \"/><title> Proyecto Algoritmos</title></head>";
	file << "<style type =\"text/css\">table,th,td{border:1px solid black;border-collapse: collapse;height: 10px;width:10px;}th,td{ padding:10px;}nav{text-align: center;padding: 20px 40px 0 0;}nav>a {margin-left: 100px;margin-right: 100px;}</style>";
	file << "<body>";
	file << "<h2>Pagina de Detalles</h2>";
	file << "<table style=\"width:100%\">";

	int pal = archivo.size();



		queue<string> values = separar(archivo, separador);

		int n = values.size();

		file << "<tr><th>#</th><th>Title</th><th>Year</th><th>Age</th><th>IMDb</th><th>Rotten Tomatoes</th><th>Netflix</th><th>Hulu</th><th>Prime Video</th><th>Disney+</th><th>type</th><tr>";



		file << "<tr>";
		for (int i = 0; i < n; i++)
		{


			file << "<td>" << values.front() << "</td>";

			values.pop();

		}


		file << "</tr>";


	file << "</table>";

	

	string devolver;

	devolver = "\"index" + valor + ".html\"";

	file << "<nav><br>";


	if (ant2 != -1)
	{
		file << "<a href=" << lista1 << "><img src=\"Atras.png\" width=\"5%\" heigth=\"5%\"></a>";
	}

	file << "<a href="<<devolver<<"><img src=\"Regresar.png\" width=\"15%\" heigth=\"15%\"></a>";


	if (dps2==tan)
	{
		control = true;
	}

	if (control !=true)
	{
		file << "<a href=" << lista2 << "><img src=\"Siguiente.png\" width=\"5%\" heigth=\"5%\"></a>";
	}


	file << "</nav>";

	file <<" </body></html>";
	file.close();

	return lista;

}