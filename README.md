# k-means_method
Целью работы является изучение алгоритма кластеризации изображений K-means   
и получение практических навыков в его реализации.  

### Результаты


Исходные данные:  

![image](https://github.com/Pogold/k-means_method/assets/93859142/f571b042-820d-4a73-b9f8-bef0f8161701)  

Случайные начальные центры кластеризации:   
32 192 64 - 0  ![image](https://github.com/Pogold/k-means_method/assets/93859142/8fa91f8b-9d3e-4716-a46c-dd3160cbcdda)  
160 64 192 - 1 ![image](https://github.com/Pogold/k-means_method/assets/93859142/bdd1c56e-138e-4375-b812-55afb4089742)  
224 192 0 - 2  ![image](https://github.com/Pogold/k-means_method/assets/93859142/187b8a4e-ed99-4157-8302-5b4d74100a83)  
160 64 192 - 3 ![image](https://github.com/Pogold/k-means_method/assets/93859142/d999789a-f052-40a6-8bed-1619fd17bb2c)  
224 192 0 - 4  ![image](https://github.com/Pogold/k-means_method/assets/93859142/e2850100-8a26-412b-866f-c0a1e04d6aa2)  

Количество кластеров: 5  
Количество пикселей: 900

---
---------------- Итерация №0 ----------------  
Расстояние от пикселя 0 к центру 0: 202.386  
Расстояние от пикселя 0 к центру 1: 239.466  
Расстояние от пикселя 0 к центру 2: 0  
Расстояние от пикселя 0 к центру 3: 239.466  
Расстояние от пикселя 0 к центру 4: 0  
Минимальное расстояние к центру 2  
Пересчитываем центр 2: 224 192 0  

Проведем классификацию пикселей:  
Расстояние от пикселя №0 к центру 0: 202.386  
Расстояние от пикселя №0 к центру 1: 237.352  
Расстояние от пикселя №0 к центру 2: 65.9471  
Расстояние от пикселя №0 к центру 3: 245.797  
Расстояние от пикселя №0 к центру 4: 0  
Пиксель №0 ближе всего к центру 4  

Результат кластеризации:   
Кластер #0  
64 192 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/966f713b-783e-4a97-a9b7-5e09fcb209e8)   
32 192 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/e0389754-fd60-40ee-abac-99fb85b61772)  
 
Кластер #1  
160 96 192  ![image](https://github.com/Pogold/k-means_method/assets/93859142/d9847546-61ce-44a9-9349-599065e4ad08)  
160 64 192  ![image](https://github.com/Pogold/k-means_method/assets/93859142/06b4beec-fb20-4810-a02f-07d8d86c2e53)  
224 160 192  ![image](https://github.com/Pogold/k-means_method/assets/93859142/4ba8b51a-5a96-477f-a196-7cd72909dcd8)  
 
Кластер #2  
224 224 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/195e3b5a-ba82-4e5a-8579-e28d16fbc251)  
192 192 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/023b2445-6c86-40b5-9ebf-276a512655ae)  
160 192 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/ad8dfef7-1941-4c96-bcd8-cdc1b0e72891)  
192 160 64  ![image](https://github.com/Pogold/k-means_method/assets/93859142/4e167d07-b854-42f1-b593-72e9ac979191)  

Кластер #3  
96 128 128  ![image](https://github.com/Pogold/k-means_method/assets/93859142/6bc2ad73-99c9-47b0-9a8b-08d1de9daf20)  
96 96 192   ![image](https://github.com/Pogold/k-means_method/assets/93859142/8488400e-428c-49e6-90b2-53b24610ce97)  
64 128 128   ![image](https://github.com/Pogold/k-means_method/assets/93859142/26a534c4-ede7-4796-8298-288208e44c33)   
64 64 192    ![image](https://github.com/Pogold/k-means_method/assets/93859142/b41f4ed0-98c8-4739-8848-b19235c9e789)  
  
Кластер #4   
224 192 0     ![image](https://github.com/Pogold/k-means_method/assets/93859142/7715c14a-50eb-4096-b40c-f9afbe407ad6)  
  
Новые центры:  
32 191.875 64 - 0  ![image](https://github.com/Pogold/k-means_method/assets/93859142/b1abf161-e12a-436c-9249-e7427b10b014)  
160 68 192 - 1  ![image](https://github.com/Pogold/k-means_method/assets/93859142/567d9659-877b-4f30-bc69-ea1228dc1079)  
207.961 192.141 64 - 2  ![image](https://github.com/Pogold/k-means_method/assets/93859142/bc857ab3-86b6-40c0-a03f-3d76e5fb3816)  
64 96 160 - 3  ![image](https://github.com/Pogold/k-means_method/assets/93859142/b34823a0-0629-4aa1-a8a1-9bc8e51864c8)  
224 192 0 - 4  ![image](https://github.com/Pogold/k-means_method/assets/93859142/316f1ebc-a5a9-4ac7-85a2-4ed2b067acc2)  

Конец кластеризации

---

Можно сделать вывод, что все центры сместились, кроме последнего.  
Алгоритм сработал корректно, так как пиксели имеют одинаковый оттенок в каждом из кластеров.  
