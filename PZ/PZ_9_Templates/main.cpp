#include <iostream>
#include <type_traits>
#include <cmath>
#include <stdexcept>
#include <typeinfo>

using namespace std;

template <typename T>
class cl_Array {
private:
    int size;
    T* data;
public:
    cl_Array(int n) {
        size =  n;
        data = new T[n];

        for (int i = 0; i != size; i += 1) {
            data[i] = T();
        }
    }

    ~cl_Array() {
        delete[] data;
    }

    void set(int index, const T& value) {
        if (index < 0 or index >= size){
            throw std::invalid_argument("Index erroe");
        }
        data[index] = value;

    }

template <typename U = T>
enable_if_t<is_arithmetic_v<U>, void>
set_checked(int index, const U& value) {

        if (index < 0 or index >= size) {
            throw invalid_argument("Index error");
        }

        if constexpr (is_floating_point_v<U>) {
            if (!isfinite(value)) {
                throw invalid_argument("Value error");
            }
        }

        if (value < 0) {
            throw invalid_argument("Value error");
        }

        data[index] = value;
    }

    friend ostream& operator<<(ostream& os, const cl_Array& arr) {
        for (int i = 0; i != arr.size; i += 1) {
            os << arr.data[i];
            if (i + 1 != arr.size) os << " ";
        }
        return os;
    }

    double distance_to(const cl_Array& other) const {
        if (size != other.size) {
            throw invalid_argument("Разные размеры");
        }

        if constexpr (!is_arithmetic_v<T>) {
            throw bad_typeid();
        } else {
            double sum = 0.0;

            for (int i = 0; i != size; i += 1) {
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff * diff;
            }

            return sqrt(sum);
        }
    }




};




int main() {
    system("chcp 65001");

    cl_Array<int> a(3);
    a.set(0, 11);
    a.set_checked(1, 22);
    a.set_checked(2, 33);
    cout << "a: " << a << "\n";

    cl_Array<int> b(3);
    b.set_checked(0, 10);
    b.set_checked(1, 20);
    b.set_checked(2, 30);

    cout << "b: " << b << "\n";

    try {
        cout << "distance(a, b) = " << a.distance_to(b) << "\n";
    } catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << "\n";
    } catch (const bad_typeid& e) {
        cout << "bad_typeid\n";
    }

}