#include<cstdio>


class Mere {
public:
 virtual void message(){
    printf("je suis la classe Mere\n");
  }
  virtual ~Mere(){
    printf("destructeur mere\n");
  }
};


class Fille : public Mere {
public:
   void message(){
    printf("je suis la classe Fille\n");
  }
  ~Fille(){
    printf("destructeur fille\n");
  }
};


int main() {
  Fille *f=new Fille();
  Mere &m=*f;
  m.message();
  delete &m;

  /*
   Fille f;
   Mere m=;
   m.message();
  */
}

/*
int main(){
  Fille *fille= new Fille;

  fille->message();

  Mere *mere=fille;
  mere->message();

  printf("Mere: %d\n",sizeof(Mere));
  printf("Fille: %d\n",sizeof(Fille));


  delete mere;
}*/

/*
int main(){
Mere *mere=NULL;

mere->message();
}*/

