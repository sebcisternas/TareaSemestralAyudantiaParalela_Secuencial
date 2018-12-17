#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


float ang,x1,x2,x3,a1,a2,a3,dis1,dis2,dis3,auxdis,nX,nY;;
string v1,v2,v3,valor1,valor2,num,x,y,linea,pA,pB,pC,aux1,aux2,aux3,aux4;
std::vector<string> A;
int cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,ang1,ang2,ang3,i;

void refinar(float ang, string pA,string pB,string pC)
{
    ofstream mon("espiralrefinada.mesh", ofstream::app);

    for(i=0;i<A.size();i++){
        aux4=A[i];
        std::istringstream iss(aux4);
        iss>>aux1>>aux2>>aux3;
        if(pA==aux1)
        {   v1=aux1;
            x1=std::stof(aux2.c_str());
            a1=std::stof(aux3.c_str());
            cout<<v1<<" "<<x1<<" "<<a1<<endl;
        }
        if(pB==aux1)
        {
            v2=aux1;
            x3=std::stof(aux2.c_str());
            a3=std::stof(aux3.c_str());
            cout<<v2<<" "<<x3<<" "<<a3<<endl;
        }
        if(pC==aux1){
            v3=aux1;
            x2=std::stof(aux2.c_str());
            a2=std::stof(aux3.c_str());
            cout<<v3<<" "<<x2<<" "<<a2<<endl;
        }
    }
    dis1=sqrt(pow((x2-x1),2)+pow((a2-a1),2));
    dis2=sqrt(pow((x3-x1),2)+pow((a3-a1),2));
    dis3=sqrt(pow((x3-x2),2)+pow((a3-a2),2));
    ang1 = acos((dis2*dis2+dis3*dis3-dis1*dis1)/(2*dis2*dis3))*180/3.1415;
    ang2 = acos((dis1*dis1+dis3*dis3-dis2*dis2)/(2*dis1*dis3))*180/3.1415;
    ang3 = acos((dis1*dis1+dis2*dis2-dis3*dis3)/(2*dis1*dis2))*180/3.1415;

    if(ang==ang1||ang==ang2||ang==ang3)
    {   cont3++;
        if(dis1>dis2 && dis1>dis3){
        auxdis=dis1/2;
        nX=(x1+auxdis*x2)/(auxdis+1);
        nY=(a1+auxdis*a2)/(auxdis+1);
        mon<<v1<<" "<<v3<<" D"<<cont3<<endl;
        mon<<v2<<" "<<v3<<" D"<<cont3<<endl;
        }
        else
        {
        if(dis2>dis3){
        auxdis=dis2/2;
        nX=(x1+auxdis*x3)/(auxdis+1);
        nY=(a1+auxdis*a3)/(auxdis+1);
        mon<<v1<<" "<<v3<<" D"<<cont3<<endl;
        mon<<v1<<" "<<v2<<" D"<<cont3<<endl;
            }
            else
        {  auxdis=dis3/2;
           nX=(x2+auxdis*x3)/(auxdis+1);
           nY=(a2+auxdis*a3)/(auxdis+1);
           mon<<v1<<" "<<v2<<" D"<<cont3<<endl;
           mon<<v2<<" "<<v3<<" D"<<cont3<<endl;
            }
        }
    }
    else
    {cont4++;
     mon<<v1<<" "<<v2<<" "<<v3<<endl;
    }
    mon.close();
}

int main()
{
    ifstream nod("espiral.node", ifstream::in);
    ifstream mall("espiral.mesh",ifstream::in);
    cout<<"------ Tarea Semestral Paralela - Secuencial ----"<<endl<<endl;
    cout<<"                Refinamiento de Triangulos       "<<endl<<endl;
    cout<<"Ingresar angulo:"<<endl;
    cin>>ang;
    do
    {   cont1++;
        nod>>num>>x>>y;
        A.push_back(num+" "+x+" "+y);

        }
    while(nod>>valor1);
    nod.close();
    do
    {   mall>>pA>>pB>>pC;
        cont2++;
        refinar(ang,pA,pB,pC);
    }
    while(mall>>valor2);
    mall.close();
    cout<<"La malla esta refinada"<<endl;
 return 0;
}

