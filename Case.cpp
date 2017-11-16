class Case {
 private:
	int pion;
	/*pourquoi rajouter un attribut position si liste de pointeurs dans le tableau ? */
	
 public:
	explicit Case (int valInit = 0) : pion(valInit){
	}
	int getPion() const {
		return pion;}
	void setPion(int val){
		pion = val;} /*attention il faut que dans le truc qui utilise ce setPion il y ai un test pour 
		que la valeur ne puisse etre que 0, 1 ou 2 avant hein ! le test ne se fait pas ici*/
};

