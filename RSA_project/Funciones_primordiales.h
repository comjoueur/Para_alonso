#include<RSA.h>
#include<stdio.h>
vector<string> Cifrar_File(string& p,pair<string,string>llave_publica){
	const char * d=p.c_str();
	FILE *mensaje=fopen(d,"rb");
	int c;
	if(mensaje==NULL){
		cout<<"NADA EN EL FILE"<<endl;
		fclose(mensaje);
	}
	else{
		cout<<<"sucedido"<<endl;
	}
	vector<ZZ>vec;
	while(1){
		c=fgetc(mensaje);
		if(c==EOF)break;
		vec.push_back(ZZ(c));
	}
	vec=Bloque(vec,2000);
	vector<string>man;
	for(int i=0;i<vec.size();i++){
		man.push_back(ZZ_a_str(vec[i]));
	}
	for(int i=0;i<man.size();i++){
		Cifrar_RSA(llave_publica,man[i]);
	}
	fclose(mensaje);
	return man;
}
vector<ZZ> Descifrar_file(vector<string>cifrado,pair<string,string>llave_privada){
	for(int i=0;i<cifrado.size(),i++)Descifrar_RSA(llave_privada,cifrado[i]);
	vector<ZZ>nuevo;
	for(int i=0;i<cifrado.size();i++) nuevo.push_back(str_a_ZZ(cifrado[i]));
	return nuevo;
}
