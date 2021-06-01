# TEORIA GRAFÓW: ALGORYTM BELLMANA - FORDA

### Algorytm Bellmana - Forda znajduje najkrótszą ścieżkę pomiędzy danymi węzłami w grafie, który nie posiada ujemnych cykli.

## 1. Uruchom program
Zainstaluj dowolny kompilator c++ oraz cmake. <br>
Przejdź do katalogu bellman_ford. <br>
Utwórz nowy katalog "build" i przejdź do niego. <br>
W katalogu "bellman_ford/build" wykonaj polecenie: cmake ../ <br>
Następnie wykonaj polecenie: make <br>
Następnie wykonaj polecenie: make run_bellman_ford <br>

## 2. Wczytaj Twój graf
Program umożliwia wczytanie grafu z pliku tekstowego zawierającego listę sąsiedztwa lub macierz incydencji. <br>
Plik z grafem należy umieścić w folderze bellman_ford/src/graphs <br>
Tam znajdziesz już przykładowe grafy. <br>
Uwaga! Zawartość pliku musi mieć odpowiedni format: <br>
### Macierz incydencji:
![incident_matrix](bellman_ford/src/images/incident_matrix.png)
### Lista sąsiedztwa:
![adjacency_list](bellman_ford/src/images/adjacency_list.png)
### Wagi krawędzi możesz przypisać losowo, badź też wczytać z pliku.
### Plik powinien zawierać macierz wag. <BR> Element w i-tym wierszu i j-tej kolumnie oznacza wagę krawędzi i --> j. 
### Przykładowy plik: 
![values](bellman_ford/src/images/values.png)
### Wagi mogą też zawierać część ułamkową:
![double_values](bellman_ford/src/images/double_values.png)

## Najpierw zdecyduj w jaki sposób chcesz wczytać swój graf:
### Aby wczytać graf z listy sąsiedztwa wybierz A:
![select_A](bellman_ford/src/images/select_A.png)
###Aby wczytać garf z macierzy incydencji wybierz I:
![select_I](bellman_ford/src/images/select_I.png)
## Następnie wybierz opcję przypisania wag krawędziom:
### Aby przypisać krawędziom losowe wartości wybierz R:
![select_R](bellman_ford/src/images/select_R.png)
### Aby przypisać krawędziom wartości zawarte w pliku wybierz F:
![select_F](bellman_ford/src/images/select_F.png)

Następnie program poprosi Cię o wpisanie nazwy pliku z reprezentacją grafu i ewentualnie nazwy pliku z wartościami krawędzi.
Pamiętaj, że musisz podać właściwą ścieżkę do pliku np. graphs/1/one_adjacency_list.txt

### Gdy graf zostanie wczytany prawidłowo otrzymasz informację o ilości wczytanych węzłów i krawędzi:
![successfully_loaded](bellman_ford/src/images/successfully_loaded.png)

## Teraz pobaw się Twoim grafem:
Możesz wypisać jego listę sąsiedztwa lub macierz incydencji lub korzystając z algorytmu Bellmana - Forda znaleźć najkrószą ścieżkę pomiędzy węzłami (program poprosi Cię o podanie indeksu węzła początkowego i końcowego).
### Kieruj się instrukcjami!
![menu](bellman_ford/src/images/menu.png)

# Przykłady:
## Graph - "ONE"
### Uwaga! Graf posiada ujemny cykl!
![one](bellman_ford/src/graphs/1/one.png)
![one_loading](bellman_ford/src/images/one_loading.png)
![one_result](bellman_ford/src/images/one_result.png)
## Graph - "TWO"
![two](bellman_ford/src/graphs/2/two.png)
![two_loading](bellman_ford/src/images/two_loading.png)
![two_result](bellman_ford/src/images/two_result.png)
## Graph - "THREE"
![three](bellman_ford/src/graphs/3/three.png)
![three_loading](bellman_ford/src/images/three_loading.png)
![three_result](bellman_ford/src/images/three_result.png)
## Graph - "MY GRAPH"
### Losowe wagi krawędzi
![my_graph](bellman_ford/src/graphs/my_graph/my_graph.png)
### Program wypisze krawędzie i ich wagi:
![random_values](bellman_ford/src/images/random_values.png)
![my_graph_loading](bellman_ford/src/images/my_graph_loading.png)
![my_graph_result](bellman_ford/src/images/my_graph_result.png)

