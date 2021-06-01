#TEORIA GRAFÓW: ALGORYTM BELLMANA - FORDA

###Algorytm Bellmana - Forda znajduje najkrótszą ścieżkę pomiędzy danymi węzłami w grafie, który nie posiada ujemnych cylki.

##1. Uruchom program
Zainstaluj dowolny kompilator c++ oraz cmake. <br>
Przejdź do katalogu bellman_ford. <br>
Utwórz nowy katalog "build" i przejdź do niego. <br>
W katalogu "bellman_ford/build" wykonaj polecenie: cmake ../ <br>
Następnie wykonaj polecenie: make <br>
Następnie wykonaj polecenie: make run_bellman_ford <br>

##2. Wczytaj Twój graf
Program umożliwia wczytanie grafu z pliku tekstowego zawierającego listę sąsiedztwa lub macierz incydencji. <br>
Plik z grafem należy umieścić w folderze bellman_ford/src/graphs <br>
Tam znajdziesz już przykładowe grafy. <br>
Uwaga zawartość pliku musi mieć odpowiedni format: <br>
### Macierz incydencji:
![graph](bellman_ford/src/images/incident_matrix.png)
### Lista sąsiedztwa:
![graph](bellman_ford/src/images/adjacency_list.png)
### Wagi krawędzi możesz przypisać losowo, badź też wczytać z pliku.
### Plik powinien zawierać macierz wag, gdzie element w i-tym wierszu i j-tej kolumnie oznacza wagę krawędzi i --> j. 
###Przykładowy plik: 
![graph](bellman_ford/src/images/values.png)
### Wagi mogą też zawierać część ułamkową:
![graph](bellman_ford/src/images/double_values.png)

##Najpierw zdecyduj w jaki sposób chcesz wczytać swój graf:
###Aby wczytać graf z listy sąsiedztwa wybierz A:
![graph](bellman_ford/src/images/select_A.png)
###Aby wczytać garf z macierzy incydencji wybierz I:
![graph](bellman_ford/src/images/select_I.png)
##Następnie wybierz opcję przypisania wag krawędziom:
###Aby przypisać krawędziom losowe wartości wybierz R:
![graph](bellman_ford/src/images/select_R.png)
###Aby przypisać krawędziom wartości zawarte w pliku wybierz F:
![graph](bellman_ford/src/images/select_F.png)

Następnie program poprosi Cię o wpisanie nazwy pliku z reprezentacją grafu i ewentualnie nazwy pliku z wartościami krawędzi.
Pamiętaj, że musisz podać właściwą ścieżkę do pliku np. graphs/1/one_adjacency_list.txt

### Gdy graf zostanie wczytany prawidłowo otrzymasz informację o ilości wczytanych węzłów i krawędzi:
![graph](bellman_ford/src/images/successfully_loaded.png)

##Teraz pobaw się Twoim grafem:
Możesz wypisać jego listę sąsiedztwa lub macierz incydencji lub korzystając z algorytmu Bellmana - Forda znaleźć najkrószą ścieżkę pomiędzy węzłami (program poprosi Cię o podanie indeksu węzła początkowego i końcowego).
###Kieruj się instrukcjami!
![graph](bellman_ford/src/images/menu.png)

#Przykłady:
##Graph - "ONE"
###Uwaga! Graf posiada ujemny cykl!
![graph](bellman_ford/src/graphs/1/one.png)
![graph](bellman_ford/src/images/one_loading.png)
![graph](bellman_ford/src/images/one_result.png)
##Graph - "TWO"
![graph](bellman_ford/src/graphs/2/two.png)
![graph](bellman_ford/src/images/two_loading.png)
![graph](bellman_ford/src/images/two_result.png)
##Graph - "THREE"
![graph](bellman_ford/src/graphs/3/three.png)
![graph](bellman_ford/src/images/three_loading.png)
![graph](bellman_ford/src/images/three_result.png)
##Graph - "MY GRAPH"
###Losowe wagi krawędzi
![graph](bellman_ford/src/graphs/my_graph/my_graph.png)
###Program wypisze krawędzie i ich wagi:
![graph](bellman_ford/src/images/random_values.png)
![graph](bellman_ford/src/images/my_graph_loading.png)
![graph](bellman_ford/src/images/my_graph_result.png)

