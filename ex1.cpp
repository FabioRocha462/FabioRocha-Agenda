#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include<iomanip>
using namespace std;
int main(){
  string nome, telefone, end;
  int id, menu=1,c=0,controlador=20;
  while(menu!=0){
    cout<<"Digite 1 para adicionar um contato: "<<endl;
    cout<<"Digite 2 para ver os contatos:"<<endl;
    cout<<"Digite 3 para remover os contatos"<<endl;
    cout<<"Digite 0 para sair"<<endl;
    cin>>menu;
    if(menu==1){
       ofstream ArqGerado;
  ArqGerado.open("saida.txt");
  if(!ArqGerado){
    cout<<"Erro"<<endl;
    abort();
  }
  if(c==1){
  ifstream infalepivo;
  infalepivo.open("saida.text");
  if(!infalepivo){
    cout<<"Erro"<<endl;
  }
  int id3;
  string nome3,telefone3,end3;
  while(infalepivo>>id3>>nome3>>telefone3>>end3){
    ArqGerado<<id3<<setw(10)<<"|"<<nome3<<setw(10)<<"|"<<telefone3<<setw(10)<<"|"<<end3<<endl;
  }
  infalepivo.close();
  c=0;
  }
  

  ArqGerado.close();
      ofstream Arqrecebe;
      Arqrecebe.open("saida.txt", ios:: app);
      if(!Arqrecebe){
        cout<<"Erro"<<endl;
      }
      string menu1="s";
      while(menu1!="sair"){
        id=rand()%100;
        cout<<"Digite o nome"<<endl;
        cin>>nome;
        cout<<"Digite o telefone"<<endl;
        cin>>telefone;
        cout<<"Digite o endereço"<<endl;
        cin>>end;
        cout<<"Digite sair para parar"<<endl;
        cin>>menu1;
        Arqrecebe<<id<<setw(10)<<"|"<<nome<<setw(10)<<
        "|"<<telefone<<setw(10)<<"|"<<end<<endl;
        controlador--;
        
      cout<<"Você ainda pode  colocar "<<controlador<<" contatos"<<endl;

      }
      Arqrecebe.close();
      
      if(controlador==1){
        cout<<"Não Tem mais espaço, só cabe mais 1"<<endl;
      }
      if(controlador==0){
        break;
      }
    }
    if(menu==2){
     
      ifstream ArqLeitura;
      ArqLeitura.open("saida.txt");
      if(!ArqLeitura){
        cout<<"Erro"<<endl;
      }
      cout<<"ID"<<setw(10)<<"|"<<"Nome"<<setw(10)<<"|"<<"Telefone"<<setw(10)<<"|"<<"Endereço"<<endl;
      int id1;
      string nome1,telefone1, end1;
      while(ArqLeitura>>id1>>nome1>>telefone1>>end1){
        cout<<id1<<setw(10)<<nome1<<setw(10)<<telefone1<<setw(10)<<end1<<endl;

      }
      ArqLeitura.close();


    }
    if(menu==3){ 
      c=0;
      ifstream InFale;
      InFale.open("saida.txt");
      if(!InFale){
        cout<<"Erro"<<endl;
        abort();
      }
      ofstream Scanfile;
      Scanfile.open("saida.text");
      if(!Scanfile){
        cout<<"Erro brabo"<<endl;
        abort();
      }
      int id2, excluir;
      string nome2,telefone2, end2;
      cout<<"Digite o que deseja Excluir"<<endl;
      cin>>excluir;
      while(InFale>>id2>>nome2>>telefone2>>end2){
        if(excluir!=id2){
          Scanfile<<id2<<setw(10)<<"|"<<nome2<<setw(10)<<"|"<<telefone2<<setw(10)<<"|"<<end2<<endl;
         
        }
      }
      InFale.close();
      Scanfile.close();
    

      
       c=1;
       controlador++;

    }
  
  }
 
  return 0;
}