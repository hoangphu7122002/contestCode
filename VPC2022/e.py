# Python3 program to demonstrate working of
# Gaussian Elimination method
# N = 3

# function to get matrix content
def gaussianElimination(mat, N):

    # reduction into r.e.f.
    singular_flag = forwardElim(mat, N)

    # if matrix is singular
    if (singular_flag != -1):

        print("Singular Matrix.")

        # if the RHS of equation corresponding to
        #   zero row  is 0, * system has infinitely
        #   many solutions, else inconsistent*/
        if (mat[singular_flag][N]):
            print("Inconsistent System.")
        else:
            print("May have infinitely many solutions.")

        return

    # get solution to system and print it using
    #   backward substitution
    return backSub(mat, N)

# function for elementary operation of swapping two rows
def swap_row(mat, i, j, N):

    for k in range(N + 1):

        temp = mat[i][k]
        mat[i][k] = mat[j][k]
        mat[j][k] = temp

# function to reduce matrix to r.e.f.
def forwardElim(mat, N):
    for k in range(N):

        # Initialize maximum value and index for pivot
        i_max = k
        v_max = mat[i_max][k]
 
        # find greater amplitude for pivot if any
        for i in range(k + 1, N):
            if (abs(mat[i][k]) > v_max):
                v_max = mat[i][k]
                i_max = i
 
        # if a principal diagonal element  is zero,
        # it denotes that matrix is singular, and
        # will lead to a division-by-zero later.
        if not mat[k][i_max]:
            return k    # Matrix is singular
 
        # Swap the greatest value row with current row
        if (i_max != k):
            swap_row(mat, k, i_max, N)
 
        for i in range(k + 1, N):
 
            # factor f to set current row kth element to 0,
            # and subsequently remaining kth column to 0 */
            f = mat[i][k]/mat[k][k]
 
            # subtract fth multiple of corresponding kth
            # row element*/
            for j in range(k + 1, N + 1):
                mat[i][j] -= mat[k][j]*f
 
            # filling lower triangular matrix with zeros*/
            mat[i][k] = 0
 
        # print(mat);        //for matrix state
 
    # print(mat);            //for matrix state
    return -1
 
# function to calculate the values of the unknowns
def backSub(mat, N):
 
    x = [None for _ in range(N)]    # An array to store solution
 
    # Start calculating from last equation up to the
    #  first */
    for i in range(N-1, -1, -1):
 
        # start with the RHS of the equation */
        x[i] = mat[i][N]
 
        # Initialize j to i+1 since matrix is upper
        #  triangular*/
        for j in range(i + 1, N):

            # subtract all the lhs values
            # except the coefficient of the variable
            # whose value is being calculated */
            x[i] -= mat[i][j]*x[j]
 
        # divide the RHS by the coefficient of the
        #  unknown being calculated
        x[i] = (x[i]/mat[i][i])
 
    print("\nSolution for the system:")
    for i in range(N):
        print("{:.8f}".format(x[i]))
    return x


def get_equation_system(matrix):
    equation_system = [[0 for i in range(len(matrix)**2+ 1)] for j in range(len(matrix)**2)]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            idx_equation = i*(len(matrix))+j
            for p in range(max(i-1, 0), min(i+2, len(matrix))):
                for q in range(max(j-1, 0), min(j+2, len(matrix))):
                    if p == i and q == j:
                        continue
                    
                    # print(i, j, p, q)
                    equation_system[idx_equation][p*len(matrix)+q] = 1
                    
            equation_system[idx_equation][-1] = matrix[i][j]
            
    # print(equation_system)   
    return equation_system     
        
def changeType(n, matrix):
    # Write your code here
    equation_system = get_equation_system(matrix)    

    return gaussianElimination(equation_system, len(matrix)**2)
    
n = 4
matrix = [[1, 2, 2, 2],
            [2, 5, 3, 2],
            [3, 5, 5, 4],
            [3, 3, 4, 1]]

# print(changeType(n, matrix))

mat = [[3.0, 2.0, -4.0, 3.0], [2.0, 3.0, 3.0, 15.0], [5.0, -3, 1.0, 14.0]]
print(gaussianElimination(mat, 3))

import numpy as np

test_eq_system = np.array(get_equation_system(matrix))
test_solutions = np.array([0,0,0,0,
                            1,0,1,1,
                            1,1,1,0,
                            0,1,0,1])
print(test_eq_system[:, :-1]@test_solutions)