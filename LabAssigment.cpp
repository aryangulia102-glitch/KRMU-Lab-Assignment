#include <iostream>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

struct InventoryItem
{
    int ItemID;
    string ItemName;
    int Quantity;
    float Price;
};

class InventorySystem
{
private:
    InventoryItem ItemArray[MAX_ITEMS];
    int itemCount;

public:
    InventorySystem() : itemCount(0) {}

    void insertItem(InventoryItem data)
    {
        if (itemCount < MAX_ITEMS)
        {
            ItemArray[itemCount++] = data;
            cout << "Item inserted.\n";
        }
        else
        {
            cout << "Inventory is full.\n";
        }
    }

    void deleteItem(int ItemID)
    {
        int found = -1;
        for (int i = 0; i < itemCount; i++)
        {
            if (ItemArray[i].ItemID == ItemID)
            {
                found = i;
                break;
            }
        }
        if (found != -1)
        {
            for (int i = found; i < itemCount - 1; i++)
            {
                ItemArray[i] = ItemArray[i + 1];
            }
            itemCount--;
            cout << "Item deleted.\n";
        }
        else
        {
            cout << "Item not found.\n";
        }
    }

    int searchItem(int ItemID, string ItemName = "")
    {
        for (int i = 0; i < itemCount; i++)
        {
            if ((ItemID != -1 && ItemArray[i].ItemID == ItemID) ||
                (!ItemName.empty() && ItemArray[i].ItemName == ItemName))
            {
                return i;
            }
        }
        return -1;
    }

    void addItemRecord(InventoryItem data)
    {
        insertItem(data);
    }

    void removeItemRecord(int ItemID)
    {
        deleteItem(ItemID);
    }

    int searchByItem(int ItemID, string ItemName = "")
    {
        return searchItem(ItemID, ItemName);
    }

    void managePriceQuantity_RowMajor()
    {
        cout << "Row-Major Price & Quantity Table:\n";
        cout << "ItemID\tPrice\tQuantity\n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << ItemArray[i].ItemID << "\t" << ItemArray[i].Price << "\t"
                 << ItemArray[i].Quantity << '\n';
        }
    }

    void managePriceQuantity_ColumnMajor()
    {
        cout << "Column-Major Price & Quantity Table:\n";
        cout << "ItemID\t";
        for (int i = 0; i < itemCount; i++)
            cout << ItemArray[i].ItemID << "\t";
        cout << "\nPrice\t";
        for (int i = 0; i < itemCount; i++)
            cout << ItemArray[i].Price << "\t";
        cout << "\nQuantity\t";
        for (int i = 0; i < itemCount; i++)
            cout << ItemArray[i].Quantity << "\t";
        cout << "\n";
    }

    void optimizeSparseStorage()
    {
        cout << "SparseMatrix for Rarely Restocked Products:\n";
        cout << "ItemID\tQuantity\tPrice\n";
        for (int i = 0; i < itemCount; i++)
        {
            if (ItemArray[i].Quantity == 0)
            {
                cout << ItemArray[i].ItemID << "\t" << ItemArray[i].Quantity << "\t"
                     << ItemArray[i].Price << "\n";
            }
        }
    }

    void showAllItems()
    {
        cout << "Full Inventory:\n";
        cout << "ItemID\tItemName\tQuantity\tPrice\n";
        for (int i = 0; i < itemCount; i++)
        {
            cout << ItemArray[i].ItemID << "\t" << ItemArray[i].ItemName << "\t"
                 << ItemArray[i].Quantity << "\t" << ItemArray[i].Price << "\n";
        }
    }
};

int main()
{
    InventorySystem inventory;

    inventory.insertItem({101, "Milk", 10, 55.0});
    inventory.insertItem({102, "Eggs", 0, 70.0});
    inventory.insertItem({103, "Bread", 5, 32.0});
    inventory.insertItem({104, "Paneer", 0, 175.0});

    inventory.showAllItems();
    cout << "\nSearching for item with ItemName 'Eggs':\n";
}