// #include <iostream>
// #include <vector>

// class ProductoftheLastKNumbers_1352
// {
// private:
//     int product = 1;
//     std::vector<int> intStream;

// public:
//     ProductoftheLastKNumbers_1352()
//     {
//     }

//     void add(int num)
//     {
//         if (num != 0)
//         {
//             this->product = this->product * num;
//             this->intStream.push_back(product);
//         }
//         else
//         {
//             intStream.clear();
//             this->product = 1;
//         }
//     }

//     int getProduct(int k)
//     {
//         int size = this->intStream.size();
//         if (k > size) // If k is greater than available numbers, return 0
//             return 0;
//         if (k == size) // If k equals the entire size, return the last stored product
//             return intStream.back();

//         return intStream.back() / intStream[size - k - 1]; // Compute the product of the last k numbers
//     }

//     void display()
//     {
//         for (auto i : intStream)
//         {
//             std::cout << i << " ";
//         }
//     }
// };
// int main()
// {
//     ProductoftheLastKNumbers_1352 *p1 = new ProductoftheLastKNumbers_1352();
//     p1->add(3);
//     p1->add(0);
//     p1->add(2);
//     p1->add(5);
//     p1->add(4);
//     std::cout << p1->getProduct(2);
//     // p1->getProduct(3);
//     // p1->getProduct(4);
//     // p1->add(8);
//     // p1->getProduct(2);
//     p1->display();
//     return 0;
// }

// /**
//  * Your ProductOfNumbers object will be instantiated and called as such:
//  * ProductOfNumbers* obj = new ProductOfNumbers();
//  * obj->add(num);
//  * int param_2 = obj->getProduct(k);
//  */

// #include <iostream>
// #include <vector>

// class ProductoftheLastKNumbers_1352
// {
// private:
//     long long product = 1; // Use long long to prevent overflow
//     std::vector<long long> intStream;

// public:
//     ProductoftheLastKNumbers_1352()
//     {
//     }

//     void add(int num)
//     {
//         if (num != 0)
//         {
//             this->product = this->product * num;
//             this->intStream.push_back(product);
//         }
//         else
//         {
//             intStream.clear();
//             this->product = 1;
//         }
//     }

//     int getProduct(int k)
//     {
//         int size = this->intStream.size();
//         if (k > size) // If k is greater than available numbers, return 0
//             return 0;
//         if (k == size) // If k equals the entire size, return the last stored product
//             return intStream.back();

//         return intStream.back() / intStream[size - k - 1]; // Compute the product of the last k numbers
//     }

//     void display()
//     {
//         for (auto i : intStream)
//         {
//             std::cout << i << " ";
//         }
//     }
// };

// int main()
// {
//     ProductoftheLastKNumbers_1352 *p1 = new ProductoftheLastKNumbers_1352();
//     p1->add(3);
//     p1->add(0);
//     p1->add(2);
//     p1->add(5);
//     p1->add(4);
//     std::cout << p1->getProduct(2) << std::endl;
//     p1->display();

//     delete p1; // Free allocated memory
//     return 0;
// }


#include <iostream>
#include <vector>

class ProductoftheLastKNumbers_1352
{
private:
    std::vector<long long> prefixProduct;
    std::vector<int> zeroIndices;

public:
    ProductoftheLastKNumbers_1352()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            zeroIndices.push_back(prefixProduct.size());
            prefixProduct.push_back(1); // temp value
        }
        else
        {
            if (prefixProduct.empty())
                prefixProduct.push_back(num);
            else
                prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k)
    {
        int size = prefixProduct.size();
        if (k > size) return 0;

        int lastIndex = size - k;

        // If there's a zero in the last k numbers, return 0
        if (!zeroIndices.empty() && zeroIndices.back() >= lastIndex)
            return 0;

        if (lastIndex == 0)
            return prefixProduct.back();

        return prefixProduct.back() / prefixProduct[lastIndex - 1];
    }

    void display()
    {
        for (auto i : prefixProduct)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    ProductoftheLastKNumbers_1352 *p1 = new ProductoftheLastKNumbers_1352();
    p1->add(46);
    p1->add(4);
    p1->add(31);
    p1->add(22);
    p1->add(23);
    p1->add(25);
    p1->add(52);
    p1->add(14);
    p1->add(8);
    p1->add(86);
    p1->add(8);
    p1->add(9);

    std::cout << p1->getProduct(2) << std::endl;
    std::cout << p1->getProduct(3) << std::endl;
    std::cout << p1->getProduct(4) << std::endl;

    p1->display();

    delete p1;
    return 0;
}
