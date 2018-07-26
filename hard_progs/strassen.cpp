#include <iostream>
using namespace std;

void print(int ** arr, int size) {
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }

}

//Функция для нахождени нужного размера матрицы----------------------------------------------------

int log_2(int size) {
    int new_size = 1;
    while (new_size < size) {
        new_size *= 2;
    }
    return new_size;
}

//Функция создания двумерного массива--------------------------------------------------------------

int ** create_matrix(int size) {
    int ** m = new int *[size];
    m[0] = new int[size * size];
    for (int i = 1; i != size; ++i)
        m[i] = m[i - 1] + size;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            m[i][j] = 0;
    return m;
}
//Функция удаления массива-------------------------------------------------------------------------

void free_matrix(int ** m, int a, int b) {
    delete [] m[0];
    delete [] m;
}

//Функция заполнения массива-----------------------------------------------------------------------

void fill(int ** to, int ** from, int pointer_i, int pointer_j, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            to[i][j] = from[i + pointer_i][j + pointer_j];
}

//Функция сложения двух матриц---------------------------------------------------------------------

void sub_matrix(int ** matr_a, int ** matr_b, int ** matr_c, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matr_c[i][j] = matr_a[i][j] - matr_b[i][j];
        }
    }
}

//Функция вычитания двух матриц--------------------------------------------------------------------

void add_matrix(int ** matr_a, int ** matr_b, int ** matr_c, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            matr_c[i][j] = matr_a[i][j] + matr_b[i][j];
        }
    }
}

//Алгоритм Штрассена-------------------------------------------------------------------------------

int ** strassen(int ** matr_a, int ** matr_b, int size) {
    int ** matr_c = create_matrix(size);
    if (size == 1)
        matr_c [0][0] = matr_a[0][0] * matr_b[0][0];
    else {
        int middle_size = size / 2;
        
        //Создание 4-ех подмассивов matr_a и их заполнение

        int ** matr_a_11 = create_matrix(middle_size);
        int ** matr_a_12 = create_matrix(middle_size);
        int ** matr_a_21 = create_matrix(middle_size);
        int ** matr_a_22 = create_matrix(middle_size);

        fill(matr_a_11, matr_a, 0, 0, middle_size);
        fill(matr_a_12, matr_a, 0, middle_size, middle_size);
        fill(matr_a_21, matr_a, middle_size, 0, middle_size);
        fill(matr_a_22, matr_a, middle_size, middle_size, middle_size);

        //Создание 4-ех подмассивов matr_b и их заполнение

        int ** matr_b_11 = create_matrix(middle_size);
        int ** matr_b_12 = create_matrix(middle_size);
        int ** matr_b_21 = create_matrix(middle_size);
        int ** matr_b_22 = create_matrix(middle_size);

        fill(matr_b_11, matr_b, 0, 0, middle_size);
        fill(matr_b_12, matr_b, 0, middle_size, middle_size);
        fill(matr_b_21, matr_b, middle_size, 0, middle_size);
        fill(matr_b_22, matr_b, middle_size, middle_size, middle_size);

        //Создание 4-ех подмассивов matr_a и их заполнение

        int ** s1 = create_matrix(middle_size);
        int ** s2 = create_matrix(middle_size);
        int ** s3 = create_matrix(middle_size);
        int ** s4 = create_matrix(middle_size);
        int ** s5 = create_matrix(middle_size);
        int ** s6 = create_matrix(middle_size);
        int ** s7 = create_matrix(middle_size);
        int ** s8 = create_matrix(middle_size);
        int ** s9 = create_matrix(middle_size);
        int ** s0 = create_matrix(middle_size);

        sub_matrix(matr_b_12, matr_b_22, s1, middle_size);
        add_matrix(matr_a_11, matr_a_12, s2, middle_size);
        add_matrix(matr_a_21, matr_a_22, s3, middle_size);
        sub_matrix(matr_b_21, matr_b_11, s4, middle_size);
        add_matrix(matr_a_11, matr_a_22, s5, middle_size);
        add_matrix(matr_b_11, matr_b_22, s6, middle_size);
        sub_matrix(matr_a_12, matr_a_22, s7, middle_size);
        add_matrix(matr_b_21, matr_b_22, s8, middle_size);
        sub_matrix(matr_a_11, matr_a_21, s9, middle_size);
        add_matrix(matr_b_11, matr_b_12, s0, middle_size);

        //Создание дополнительных матриц p_i

        int ** p1 = create_matrix(middle_size);
        int ** p2 = create_matrix(middle_size);
        int ** p3 = create_matrix(middle_size);
        int ** p4 = create_matrix(middle_size);
        int ** p5 = create_matrix(middle_size);
        int ** p6 = create_matrix(middle_size);
        int ** p7 = create_matrix(middle_size);
 
        //Рекурсивное вычисление матриц p_i

        p1 = strassen(matr_a_11, s1, middle_size);
        p2 = strassen(s2, matr_b_22, middle_size);
        p3 = strassen(s3, matr_b_11, middle_size);
        p4 = strassen(matr_a_22, s4, middle_size);
        p5 = strassen(s5, s6, middle_size);
        p6 = strassen(s7, s8, middle_size);
        p7 = strassen(s9, s0, middle_size);

        //Заполнение матрицы matr_c

        for (int i = 0; i < middle_size; ++i)
            for (int j = 0; j < middle_size; ++j) {
                matr_c[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
                matr_c[i][j + middle_size] = p1[i][j] + p2[i][j];
                matr_c[i + middle_size][j] = p3[i][j] + p4[i][j];
                matr_c[i + middle_size][j + middle_size] = p5[i][j] + p1[i][j] - p3[i][j] - p7[i][j];
            }
        }
    return matr_c;
}

//Основная функция---------------------------------------------------------------------------------

int main() {

    //Инициализация переменных размера и массивов

    int original_size = 0;
    cin >> original_size;

    //Переопределяем размер исходных матриц

    int size = log_2(original_size);

    int ** matrix_a = 0;
    int ** matrix_b = 0;
    int ** matrix_c = 0;

    //Создание массивовoв

    matrix_a = create_matrix(size);
    matrix_b = create_matrix(size);
    matrix_c = create_matrix(size);

    //Заполнение массива matrix_a

    for (int i = 0; i < original_size; ++i) {
        for (int j = 0; j < original_size; ++j) {
            cin >> matrix_a[i][j];
        }
        cout << endl;
    }

    //Заполнение массива matrix_b

    for (int i = 0; i < original_size; ++i) {
        for (int j = 0; j < original_size; ++j) {
            cin >> matrix_b[i][j];
        }
        cout << endl;
    }

    //Применение алгоритма штрассена к массивам matrix_a и matrix_b, результат в массив matrix_c

    matrix_c = strassen(matrix_a, matrix_b, size);

    print(matrix_c, original_size);

    return 0;
}