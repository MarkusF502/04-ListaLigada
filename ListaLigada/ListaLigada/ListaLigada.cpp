
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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	int novoDup = novo->valor;
	NO* valorDup = posicaoElemento(novoDup);

	if (valorDup != NULL) {
		cout << "Esse elemento ja esta na lista" << endl;
		return;
	} else {
		if (primeiro == NULL)
		{
			primeiro = novo;
		}
		else
		{
			// procura o final da lista
			NO* aux = primeiro;
			while (aux->prox != NULL) {
				aux = aux->prox;
			}
			aux->prox = novo;
		}
	}
}

/*Explicação da solução:
Primeiro a função verifica se a ista está vazia (no primeiro if)
Depois ele pede para o usuário digitar um elemento.
Esse while vai comparando os valores da lista até achar o valor igual ao que o usuário digitou.
Se o elemento não for encontrado, então a váriavel atual será igual a NULL, o que vai acionar o próximo if.
O último if testa se o elemento a ser excluído será o primeiro da lista, caso positivo o nó primeiro será atualizado para o prox.
Se o elemento estiver no meio da lista, o nó anterior desse elemento vai apontar para a variável que vem depois do elemento que será excluído.
*/

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "A lista esta vazia" << endl;
		return;
	}
	 int busca;
    cout << "Digite um elemento para excluí-lo: ";
    cin >> busca;

    NO* atual = primeiro;
    NO* anterior = NULL;
    while (atual != NULL && atual->valor != busca) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        cout << "Elemento não encontrado na lista." << endl;
        return;
    }
    if (atual == primeiro) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }
    free(atual);
    cout << "Elemento excluído com sucesso!" << endl;
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "A lista esta vazia" << endl;
} else{
		int busca;
		cout << "Digite um elemento para efetuar a busca" << endl;
		cin >> busca;
		NO* posicao = posicaoElemento(busca);
	

		if (posicaoElemento(busca) == NULL) {
			cout << "Este elemento nao existe na lista." << endl;
		}
		else {
			cout << "Este elemento se encontra na posicao " << posicao << endl;
		}
	}
	

}


// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
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
}
