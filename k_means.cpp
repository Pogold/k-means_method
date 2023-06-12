 #include "k_means.h"

//Реализация конструктора для инициализации пикселей из массива.
K_means::K_means(int n, rgb* mas, int n_klaster)
{
	for (int i = 0; i < n; i++) {
		pixcel.push_back(*(mas + i));
	}
	q_klaster = n_klaster;
	k_pixcel = n;
	identify_centers();
}


inline double K_means::compute (rgb k1, rgb k2) //встроенные методы для расчета расстояния между пикселями и пересчета центров соответственно
{
	return sqrt(pow((k1.r - k2.r), 2) + pow((k1.g - k2.g), 2) + pow((k1.b - k2.b), 2));  //евклидово расстояние между точками в пространстве
}

inline double K_means::compute_s(double a, double b) {
	return (a + b) / 2;
};

void K_means::fill(List<int> a, int sz, int num)
{
	for (size_t i = 0; i < sz; i++)
	{
		a.push_back(num);
	}

}

//метод для выбора начальных центров кластеризации и добавления их в вектор центров.
//Осуществляется проверка на повтор центров и замена их в этих случаях.
void K_means::identify_centers()
{
	srand((unsigned)time(NULL));
	rgb temp;
	rgb *mas = new rgb[q_klaster];
	for (int i = 0; i < q_klaster; i++) {
		temp = pixcel[0 + rand() % k_pixcel];
		for (int j = i; j < q_klaster; j++) {
			if (temp.r != mas[j].r && temp.g != mas[j].g && temp.b != mas[j].b) {
				mas[j] = temp;
			}
			else {
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < q_klaster; i++) {
		centr.push_back(mas[i]);
	}
	delete []mas;
}


void K_means::clustering(ostream & os) //Основной метод кластеризации.
{
	os << "\n\nНачало кластеризации:" << endl;
	/*В эти векторы мы будем помещать информацию о принадлежности каждого пикселя к определенному кластеру: в одном векторе будет информация о предыдущей итерации, 
	а в другом - о текущей, и если они равны, то цикл заканчивается, так как каждый пиксель остался на своем месте.*/
	List<int> check_1;
	List<int> check_2;

	fill(check_1,k_pixcel, -1);
	fill(check_2, k_pixcel, -2);

	/*Количество итераций.*/
	int iter = 0;

	while(true)
	{
		os << "\n\n---------------- Итерация №" 
			<< iter << " ----------------\n\n";
		{
			for (int j = 0; j < k_pixcel; j++) {
				double *mas = new double[q_klaster];

				/*Первая часть алгоритма: берем пиксель и находим расстояние от него до каждого центра.
				Данные помещаем в динамический массив размерностью, равной количеству кластеров.*/
				for (int i = 0; i < q_klaster; i++) {
					*(mas + i) = compute(pixcel[j], centr[i]);
					os << "Расстояние от пикселя " << j << " к центру #" 
						<< i << ": " << *(mas + i) << endl;
				}

				/*Определяем минимальное расстояние и в m_k фиксируем номер центра для дальнейшего пересчета.*/
				double min_dist = *mas;
				int m_k = 0;
				for (int i = 0; i < q_klaster; i++) {
					if (min_dist > *(mas + i)) {
						min_dist = *(mas + i);
						m_k = i;
					}
				}

				os << "Минимальное расстояние к центру #"  << m_k << endl;
				os << "Пересчитываем центр #" << m_k << ": ";
				centr[m_k].r = compute_s(pixcel[j].r, centr[m_k].r);
				centr[m_k].g = compute_s(pixcel[j].g, centr[m_k].g);
				centr[m_k].b = compute_s(pixcel[j].b, centr[m_k].b);
				os << centr[m_k].r << " " << centr[m_k].g 
					<< " " << centr[m_k].b << endl;
				delete[] mas;
			}

			/*Классифицируем пиксели по кластерам.*/
			int* mass = new int[k_pixcel];
			os << "\nПроведем классификацию пикселей: "<< endl;
			for (int k = 0; k < k_pixcel; k++) {
				double *mas = new double[q_klaster];

				/*Находим расстояние до каждого центра.*/
				for (int i = 0; i < q_klaster; i++) {
					*(mas + i) = compute(pixcel[k], centr[i]);
					os << "Расстояние от пикселя №" << k << " к центру #" 
						<< i << ": " << *(mas + i) <<endl;
				}

				/*Определяем минимальное расстояние.*/
				double min_dist = *mas;
				int m_k = 0;
				for (int i = 0; i < q_klaster; i++) {
					if (min_dist > *(mas + i)) {
						min_dist = *(mas + i);
						m_k = i;
					}
				}
				mass[k] = m_k;
				os << "Пиксель №" << k << " ближе всего к центру #" << m_k << endl;
			}

			/*Выводим информацию о принадлежности пикселей к кластерам и заполняем вектор для сравнения итераций.*/
			os << "\nМассив соответствия пикселей и центров: \n";
			for (int i = 0; i < k_pixcel; i++) {
				os << mass[i] << " ";
				check_1[i] = *(mass + i);
			}
			os <<endl << endl;

			os << "Результат кластеризации: " << endl;
			for (int i = 0; i < q_klaster; i++) {
				os << "Кластер #" << i <<endl;
				for (int j = 0; j < k_pixcel; j++) {
					if (mass[j] == i) {
						os << pixcel[j].r << " " << pixcel[j].g
							<< " " << pixcel[j].b << endl;
						
					}
				}
			}

			delete[] mass;

/*Выводим информацию о новых центрах.*/
			os << "Новые центры: \n" ;
			for (int i = 0; i < q_klaster; i++) {
				os << centr[i].r << " " << centr[i].g
					<< " " << centr[i].b << " - #" << i <<endl;
			}
		}

		iter++;
		/*Если наши векторы равны или количество итераций больше допустимого – прекращаем процесс.*/
		if (check_1 == check_2 || iter >= max_iterations) {
			break;
		}
		check_2 = check_1;
	}
	os << "\n\nКонец кластеризации." << endl;
	cout << "clustering completed!" << endl << endl;
}

//Вывод начальных данных.
ostream & operator<<(ostream & os,  K_means & k)
{
	os << "Начальные пиксели: " <<endl;
	for (int i = 0; i < k.k_pixcel; i++) {
		os << k.pixcel[i].r << " " << k.pixcel[i].g
			<< " " << k.pixcel[i].b << " - №" << i << endl;
	}
	os << endl << "Случайные начальные центры кластеризации: " << endl;
	for (int i = 0; i < k.q_klaster; i++) {
		os << k.centr[i].r << " " << k.centr[i].g << " "
			<< k.centr[i].b << " - #" << i << endl;
	}
	os << "\nКоличество кластеров: " << k.q_klaster << endl;
	os << "Количество пикселей: " << k.k_pixcel << endl;
	return os;
}


//деструктор
K_means::~K_means()
{
}
