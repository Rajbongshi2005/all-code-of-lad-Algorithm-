#include <iostream>
using namespace std;

int matrix[100][100], distances[100];
const int INF = 99999;

void bellmanFord(int starting_node, int node_number) {

    for (int i = 0; i < node_number; i++) {
        distances[i] = INF;
    }

    distances[starting_node] = 0;

    for (int i = 0; i < node_number - 1; i++) {
        for (int j = 0; j < node_number; j++) {
            for (int z = 0; z < node_number; z++) {

                if (matrix[j][z] != 0 && distances[j] != INF) {
                    if (distances[j] + matrix[j][z] < distances[z]) {
                        distances[z] = distances[j] + matrix[j][z];
                    }
                }

            }
        }
    }
}

bool negativeCycle(int node_number) {

    for (int j = 0; j < node_number; j++) {
        for (int z = 0; z < node_number; z++) {

            if (matrix[j][z] != 0 && distances[j] != INF) {
                if (distances[j] + matrix[j][z] < distances[z]) {
                    return true;
                }
            }

        }
    }

    return false;
}

void Making_matrix(int node_number) {

    cout << "-------Making matrix--------\n";

    for (int i = 0; i < node_number; i++) {
        for (int j = 0; j < node_number; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "------------ the matrix--------\n";

    for (int i = 0; i < node_number; i++) {
        for (int j = 0; j < node_number; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {

    int startng_node;
    int node_number;

    cout << "Enter node number: ";
    cin >> node_number;

    Making_matrix(node_number);

    cout << "Enter the starting_node: ";
    cin >> startng_node;

    bellmanFord(startng_node, node_number);

    if (negativeCycle(node_number)) {
        cout << "Negative Cycle Detected\n";
    } 
    else {
        for (int i = 0; i < node_number; i++) {
            cout << "Distance from " << startng_node 
                 << " to " << i << " = " << distances[i] << endl;
        }
    }

    return 0;
}