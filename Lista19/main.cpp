#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ItemSet
{
private:
    vector<string> itens;

public:
    ItemSet() {}

    int localizaItem(const string &item_a_buscar) const
    {
        for (int i = 0; i < itens.size(); i++)
        {
            if (itens[i] == item_a_buscar)
            {
                return i;
            }
        }
        return -1;
    }

    bool inserir(const string &s)
    {
        int consultar_existencia_item = localizaItem(s);

        if (consultar_existencia_item != -1)
        {
            return false;
        }
        else
        {
            itens.push_back(s);
            return true;
        }
    }

    bool excluir(const string &s)
    {
        int consultar_existencia_item = localizaItem(s);
        if (consultar_existencia_item != -1)
        {
            itens.erase(itens.begin() + consultar_existencia_item);
            return true;
        }
        else
        {
            return false;
        }
    }

    void listar() const
    {
        for (const string &item : itens)
        {
            cout << item << endl;
        }
    }

    ItemSet &operator=(const ItemSet &B)
    {
        if (this == &B)
        {
            return *this; // Evitar auto-atribuição
        }

        itens.clear(); // Limpar os itens atuais

        for (const string &item : B.itens) // itens em B
        {
            inserir(item); // insere em A
        }

        return *this;
    }

    ItemSet operator+(const ItemSet &C) const
    {
        ItemSet uniao = *this; // Cria uma cópia de A
        for (const string &item : C.itens) // itens em C
        {
            if (localizaItem(item) == -1) // não encontrado em A
            {
                uniao.inserir(item); // Adicionar à união
            }
        }
        return uniao;
    }

    ItemSet operator*(const ItemSet &C) const
    {
        ItemSet intersecao;
        for (const string &item : itens)
        {
            if (C.localizaItem(item) != -1) // Se o item estiver em ambos os conjuntos
            {
                intersecao.inserir(item); // Adicionar à interseção
            }
        }
        return intersecao;
    }

    ItemSet operator-(const ItemSet &C) const
    {
        ItemSet diferenca;
        for (const string &item : itens)
        {
            if (C.localizaItem(item) == -1) // Se o item não estiver em C
            {
                diferenca.inserir(item);
            }
        }
        return diferenca;
    }

    bool operator==(const ItemSet &C) const
    {
        return itens == C.itens;
    }

    bool operator!=(const ItemSet &C) const
    {
        return !(*this == C);
    }
};

int main()
{
    
    ItemSet A;
    ItemSet B;
    ItemSet C;

    B.inserir("bola");
    B.inserir("carrinho");
    B.inserir("botão");
    B.inserir("Grampo");
    B.inserir("caneta");
    B.inserir("caderno");

    C.inserir("botão");
    C.inserir("Grampo");
    C.inserir("caneta");
    C.inserir("caderno");
    C.inserir("Olhos");

    A = B;
    cout << endl << "Itens na lista A = B" << endl;
    A.listar();

    A = B + C;
    cout << endl << "Itens na lista A = B + C" << endl;
    A.listar();

    A = B * C;
    cout << endl << "Itens na lista A = B * C" << endl;
    A.listar();

    A = B - C;
    cout << endl << "Itens na lista A = B - C" << endl;
    A.listar();

    // Verificar igualdade
    B = C;
    if (B == C)
    {
        cout << "B é igual a C" << endl;
    }
    else
    {
        cout << "B não é igual a C" << endl;
    }

    // Verificar desigualdade
    if (B != C)
    {
        cout << "B não é igual a C" << endl;
    }
    else
    {
        cout << "B é igual a C" << endl;
    }

    return 0;
}
