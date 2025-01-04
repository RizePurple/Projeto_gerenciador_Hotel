#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
using namespace std;

void limpar();
void menu();
void menu_precos();
void inforPessoais();
void inforQuartoss();
void InforAtratividades();

int numQ=144;
bool atu=false;
// classe mãe de todos os funcionarios e clientes do hotel

class Hospede {
  public:
    string nome;
    int numero_telefone;
    int idade;
    int id[144];
    

  Hospede(string n, int nt, int i):nome(n), numero_telefone(nt), idade(i) {}

  void setNome(string n){
    nome=n;
  }
  string getNome(){
    return nome;
  }
  void setIdade(int i){
    idade=i;
  }
  int getIdade(){
    return idade;
  }

  void setNum_tel(int nt){
    numero_telefone = nt;
  }
  int getNum_tel(){
    return numero_telefone;
  }
  void setid(int i){
    for(i=0;i<=144;++i){
      id[i]=i;
    }
  }
};

// classe mãe de todos os quartos ocupados por clientes
class Quarto{
  public:
    int numero;
    int classificacao;
    int servico_quarto; // basico, medio, avancado, vip.
    int tipo_quarto; // solteiro = 36, duplo solteiro, quarto de casal, quarto dormitorio.

  Quarto(int n, int sq, int tq, int c) : numero(n),classificacao(c),servico_quarto(sq), tipo_quarto(tq){}
    void setNum(int n){
      numero=n;
    }
    int getNum(){
      return numero;
    }
    void setclass(int c){
      classificacao=c;
    }
    string getclass(){
      string tipo_classi;
      switch(classificacao){
        case 1:
          tipo_classi = "STANDART";
          return tipo_classi;
          break;
        case 2:
          tipo_classi = "MASTER";
          return tipo_classi;
          break;
        case 3:
          tipo_classi = "MASTER SUPERIOR";
          return tipo_classi;
          break;
        default:
        tipo_classi = "Classificação não reconhecida, tente novamente";
        return tipo_classi;
      }
    }

    void setTipoServico(int sq){
      servico_quarto = sq;
    }

    string getservice(){
      string tipo;
      switch(servico_quarto){
        case 1:
          tipo = "TIPO BASICO";
          return tipo;
          break;
        case 2:
          tipo = "TIPO MEDIO";
          return tipo;
          break;
        case 3:
          tipo = "TIPO AVANÇADO";
          return tipo;
          break;
        case 4:
          tipo = "TIPO VIP";
          return tipo;
          break;
        default:
        tipo = "Tipo não reconhecido, tente novamente";
        return tipo;
      }
    }

    void setTipoQuarto(int tq){
      tipo_quarto = tq;
    }
    string escolha_tipo_quarto(){
      string tipo;
      if(tipo_quarto==1){
          tipo = "SOLTEIRO";
        return tipo;
      }else if (tipo_quarto==2){
          tipo = "DUPLO SOLTEIRO";
        return tipo;
      }else if(tipo_quarto==3){
          tipo = "QUARTO DE CASAL";
        return tipo;
      }else if (tipo_quarto==4){
          tipo = "QUARTOS DORMITÓRIOS";
        return tipo;
      }else{
        tipo ="O tipo não foi detectado, tente novamente!!";
        return tipo;
      }
    }
};

class Standart : public Hospede, Quarto{
public:
    Standart() :  Hospede("nome", 0, 0),Quarto(0,0,0,0){}
    void Atratividades(){
      cout << "Cama Básica e confortável" << endl;
      cout << "Banheiro Pequeno" << endl;
      cout << "Uma janela Grande"<< endl;
      cout << "Tv a cabo 30 polegadas" << endl;
    }
};
class Master : public Hospede, Quarto{
public:
    Master() :  Hospede("nome", 0, 0),Quarto(0,0,0,0){}
    void Atratividades(){
      cout << "Cama Média" << endl;
      cout << "Banheiro Mediano" << endl;
      cout << "Uma janela grande e uma pequena"<< endl;
      cout << "Frigobar" << endl;
      cout << "Tv a cabo 50 polegadas" << endl;
    }
};
class MasterSuperior : public Hospede, Quarto{
public:
    MasterSuperior() :  Hospede("nome", 0, 0),Quarto(0,0,0,0){}
    void Atratividades(){
      cout << "Cama Confortável e grande" << endl;
      cout << "Banheiro Grande" << endl;
      cout << "Duas janelas grandes"<< endl;
      cout << "Sala de cinema"<<endl;
    }
};
vector<Hospede> InforCliente;
vector<Quarto> InforQuartos;

class GerenciadorHotel{
public:
  GerenciadorHotel(){}
  void InforCancelamento(){
    for(int i=0;i<=InforCliente.size()-1;i++){
      cout << i << " - " << InforCliente[i].getNome() << "\n"<< endl;
    }
  }
  void Cancelamento(int e){
      if(e >= 0 && e < InforCliente.size()) {
          InforCliente.erase(InforCliente.begin()+e);
          atu=true;
      }
  }
 void atualizar(){
    if(atu==true){
      numQ++;
  }else{
      numQ--;
  }
 }
  int Disponibilidade(){
     int disp = numQ-InforQuartos.size();
     return disp;
  }
 
};





int main() {
  
  lula:
  cout << "---Bem-vindo ao Hotel Sussurros do Bosque---" << endl;

  menu();
  int res;
  cin>>res;
  limpar();
  if(res==1){
    //INFORMAÇÕES CLIENTES
    string nome;
    int idade;
    int numTel;
    cout << "Informe seu nome: " << endl;
    cin >> nome;
    cout << "Informe sua idade: " << endl;
    cin >> idade;
    cout << "Informe o seu numero de telefone: " << endl;
    cin >> numTel;

    Hospede p1(nome, numTel, idade);
    InforCliente.push_back(p1);
    limpar();

    //INFORMAÇÕES QUARTOS
    //tabela
    cout << "Agora veja a tabela de preços e quando se sentir seguro com a escolha pressione alguma tecla" << endl;
    menu_precos();
    char b;
    cin>>b;
    limpar();
    //ESCOLHAS DO QUARTO
    cout << "Agora personalize o quarto de sua preferencia!!\n " << endl;
    int escolha;
    int tipo;
    cout << "Escolha o tipo de serviço que deseja: \n1 - BASICO\n2 - MEDIO\n3 - AVANCADO\n4 - VIP\n" << endl;
    cin >> escolha;
    limpar();
    cout << "Escolha o tipo de quarto que deseja: \n1 - SOLTEIRO\n2 - DUPLO SOLTEIRO\n3 - QUARTO DE CASAL\n4 - QUARTOS DORMITORIOS\n" << endl;
    cin >> tipo;
    limpar();
  
    cout<<"Qual classificação de quarto o hospede deseja?\n1-STANDART\n2-MASTER\n3-MASTER SUPERIOR" << endl;
    int classi;
    cin>>classi;
    limpar();
    std::random_device rd;
    std::mt19937 gen(rd());

    int min = 1; // Valor mínimo do intervalo
    int max = 144; // Valor máximo do intervalo

    std::uniform_int_distribution<> distrib(min, max);

    // Gera um número aleatório entre min e max (inclusive)
    int randomNumber = distrib(gen);    

    
    limpar();
    Quarto person(randomNumber,escolha, tipo, classi);
    InforQuartos.push_back(person);
    inforPessoais();
    inforQuartoss();

    cout << "\nReserva Concluída\n\nPressione alguma tecla para continuar"<<endl;
    char aperta;
    cin>>aperta;
    limpar();
    goto lula;
  }
  else if(res==2){
     cout << "---Cancele sua reserva aqui!---"<<endl;
     cout << "---Escolha a reserva que deseja apagar---" << endl;
    GerenciadorHotel teste1;
    teste1.InforCancelamento();
    GerenciadorHotel teste2;
    int e;
    cin>>e;
    teste2.Cancelamento(e);
    teste2.atualizar();
    cout << "\nReserva cancelada com sucesso!\n" << "\nPressione alguma tecla para prosseguir\n"<< endl;
    char p;
    cin >>p;
    limpar();
    goto lula;
  }
   else if(res==3){
    cout << "---Essa é a quantidade de quartos disponíveis no hotel Sussurros Do Bosque---" << endl;
    GerenciadorHotel disp;
    cout << "\n" << disp.Disponibilidade() << " quartos disponíveis";
    cout << "\nPressione alguma tecla para prosseguir\n" << endl;
    char p; 
    cin>>p;
    limpar();
    goto lula;
  }else if(res==4){
    int t;
     InforAtratividades();
     cin >> t;
     if(t==1){
        Standart p;
        p.Atratividades();
        char t;
        cout << "\nPressione alguma tecla para continuar" << endl;
        cin >> t;
        limpar();
        goto lula;
     }
     if(t==2){  
        Master g;
        g.Atratividades();
        char h;
        cout << "\nPressione alguma tecla para continuar" << endl;
        cin >> h;
        limpar();
        goto lula;
    }
     if(t==3){
       MasterSuperior g;
       g.Atratividades();
       char h;
       cout << "\nPressione alguma tecla para continuar" << endl;
       cin >> h;
       limpar();
       goto lula;
    }
  }
  else{
    
    cout << "Obrigado pela preferencia ao hotel Sussuros do Bosque.\nVolte sempre!";
  }
  
}

void limpar(){
  int limpa = system("clear");
  limpa++;
}
void menu(){
  cout << "---Menu Hotel Sussurros do Bosque---" << endl;
  cout << "1 - Fazer Reserva" << endl;
  cout << "2 - Cancelar Reserva" << endl;
  cout << "3 - Disponibilidades de quartos" << endl;
  cout << "4 - Atributos do Quarto" << endl;
  cout << "5 - Sair" << endl;
}
void menu_precos(){
  cout << "\nEstes são os seguintes preços para o quarto STANDART e seus respectivos tipos:\n" << endl;
  cout << "Dormitório: R$100.00\nCasal: R$200.00\nDuplo Solteiro: R$130.00\nSolteiro: R$120.00" << endl;
  cout << "\nEstes são os seguintes preços para o quarto MASTER e seus respectivos tipos:\n" << endl;
  cout << "Dormitório: R$150.00\nCasal: R$300.00\nDuplo Solteiro: R$160.00\nSolteiro: R$140.00" << endl;
  cout << "\nEstes são os seguintes preços para o quarto MASTER SUPERIOR e seus respectivos tipos:\n" << endl;
  cout << "Dormitório: R$200.00\nCasal: R$400.00\nDuplo Solteiro: R$190.00\nSolteiro: R$160.00" << endl;
}


void inforPessoais(){
  
  cout << "---Informações Pessoais--- "<<endl;
  cout << "NOME: " << InforCliente[InforCliente.size()-1].getNome() << endl;
  cout << "IDADE: " << InforCliente[InforCliente.size()-1].getIdade() << endl;
  cout << "TELEFONE: " << InforCliente[InforCliente.size()-1].getNum_tel() << endl;
  
}

void inforQuartoss(){
  cout << "---Informações do Quarto---" << endl;
  cout <<"Classificação: " << InforQuartos[InforQuartos.size()-1].getclass() << endl;
  cout << "Tipo: " << InforQuartos[InforQuartos.size()-1].escolha_tipo_quarto() << endl;
  cout << "Serviço: " << InforQuartos[InforQuartos.size()-1].getservice() << endl;
  cout << "O numero do seu quarto é: " << InforQuartos[InforQuartos.size()-1].getNum() << endl;
}

void InforAtratividades(){
  cout << "1 - Standart" << endl;
  cout << "2 - Master" << endl;
  cout << "3 - Master Superior" << endl;
}


