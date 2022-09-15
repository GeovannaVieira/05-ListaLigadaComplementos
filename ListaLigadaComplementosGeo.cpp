#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
    NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		cout << "Sem espaço na memória!";
        return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

    NO* encontrado = posicaoElemento(novo->valor);
	if (encontrado == NULL)
    {
		cout << "O elemento digitadojá está na lista! Tente novamente! \n";
		return;
	}
		if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro;

	    NO* deslocar = NULL;
		while (aux->prox == NULL) {
			if (novo->valor < aux->prox->valor) {
                     deslocar = aux->prox;
                     aux->prox = novo;
                     novo->prox = deslocar;
                     cout << "Elemento adicionado!" << endl;
                     break;
		}
        else {
		      aux = aux->prox;
	}
}
        while (aux->prox == NULL) {
			if (novo->valor < aux->valor) {
                     primeiro = novo;
                     novo->prox = aux;

            }
            else {
                    cout << "Elemento adicionado!" << endl;
                    aux->prox = novo;
            }
        }
    }
}
else {
        cout << "Este elemento já existe na lista \n";
}
void excluirElemento()
{
        int valor;
        cout << "Digite o elemento a ser excluido: \n";
        cin >> valor;
        NO* aux = primeiro;

        while (aux->prox != NULL) {

            NO* prox = aux->prox;

            if (primeiro->valor == valor) {
                   free(primeiro)
                   primeiro = nextElement;
                   break;
        }

        if(nextElement->valor == valor) {
               aux->prox = nextElement->prox;
               free(nextElement)
               break;
        }
        aux = aux->prox;
}

void buscarElemento()
{
int valor;
	cout << "Digite o valor a ser buscado: \n ";
	cin >> valor;
	NO* element = posicaoElemento(valor);

	if(element == NULL) {
		cout << "Nenhum elemento com esse valor encontrado.";
		return;
	}

	cout << element->valor;
}
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;

