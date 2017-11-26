#include"Operaciones_matematicas_rsa.h"
class datos_RSA{
	protected:
	ZZ prime1;
	ZZ prime2;
	ZZ llave_publica;
	ZZ n;
	ZZ r;
	ZZ llave_privada;
	vector<ZZ>cifrado;
	string mensaje;
	datos_RSA(){
		prime1=0;prime2=0;llave_publica=0;
	}
};
class RSA_cifrador :private datos_RSA{
	public:
	RSA_cifrador(pair<ZZ,ZZ>par){
		this->llave_publica = par.first;
		this->n=par.second;
	}
	void cifrar(){
		cifrado=Bloque(caracter(mensaje),80);
		for(int i=0;i<cifrado.size();i++)
			cifrado[i]=Expo_mod(cifrado[i],llave_publica,n);
	}
	vector<ZZ> get_cifrado(){
		return cifrado;
	}
	void set_mensaje(string val){
		mensaje=val;
	}
};
class RSA_descifrador:private datos_RSA{
	public:
	RSA_descifrador(pair<ZZ,ZZ>par){
		this->llave_privada = par.first,
		this->n=par.second;
	}
	void descifrar(){
		vector<ZZ>vec;
		for(int i=0;i<cifrado.size();i++)
			vec.push_back(Expo_mod(cifrado[i],llave_privada,n));
		mensaje=numero(Desbloque(vec));
	}
	string get_mensaje(){
		return mensaje;
	}
	void set_cifrado(vector<ZZ>val){
		cifrado=val;
	}
};
class operations_RSA:protected datos_RSA{
	protected:
	operations_RSA(ZZ val_prime1,ZZ val_prime2,ZZ val_llave_publica){
		this->prime1=val_prime1;
		this->prime2=val_prime2;
		this->llave_publica=val_llave_publica;
		this->n=prime1*prime2;
		this->r=(prime1-ZZ(1))*(prime2-ZZ(1));
		this->llave_privada=Div_mod(llave_publica,r);
	}
};
class CalculoRSA:private operations_RSA{
	public:
	CalculoRSA(ZZ val_prime1,ZZ val_prime2,ZZ val_llave_publica=Random_prime(100)):
		operations_RSA(val_prime1,val_prime2,val_llave_publica)
		{}
	CalculoRSA():
		operations_RSA(Random_prime(),Random_prime(),Random_prime(100))
		{}
	pair<ZZ,ZZ> get_llave_publica(){
		return make_pair(llave_publica,n);
	}
	pair<ZZ,ZZ> get_llave_privada(){
		return make_pair(llave_privada,n);
	}
};
class RSA{
	public:
	pair<ZZ,ZZ>llave_publica;
	pair<ZZ,ZZ>llave_privada;
	vector<ZZ>cifrado;
	string mensaje;
};
