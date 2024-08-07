def addition(poly1, poly2):
    n = max(len(poly1), len(poly2))
    
    poly1 = poly1 + [0] * (n - len(poly1))
    poly2 = poly2 + [0] * (n - len(poly2))
    
    add = [poly1[i] + poly2[i] for i in range(n)]
    
    return add

def subtraction(poly1, poly2):
    n = max(len(poly1), len(poly2))
    
    poly1 = poly1 + [0] * (n - len(poly1))
    poly2 = poly2 + [0] * (n - len(poly2))
    
    difference = [poly1[i] - poly2[i] for i in range(n)]
    
    return difference


def multiply(A, B):

    prod = [0] * (len(A) + len(B) - 1) 

    for i in range(len(A)):
        for j in range(len(B)):
            prod[i + j] += A[i] * B[j]

    return prod

def print_polynomial(poly):
    n = len(poly) - 1
    poly_str = ""
    
    for i in range(n, -1, -1):
        coef = poly[i]
        if coef != 0:
            if i != n:
                if coef > 0:
                    poly_str += " + "
                else:
                    poly_str += " - "
                    coef = -coef
            if i == 0:
                poly_str += f"{coef}"
            elif i == 1:
                poly_str += f"{coef}x"
            else:
                poly_str += f"{coef}x^{i}"
    
    if poly_str == "":
        poly_str = "0"
    
    print(poly_str)

def main():
    n1 = int(input("Enter the highest power of the first polynomial\n"))
    poly1 = []
    
    for i in range(n1 + 1):
        x = int(input(f"Enter the coefficient for the exponent {i}\n"))
        poly1.append(x)

    n2 = int(input("Enter the highest power of the second polynomial\n"))
    poly2 = []
    
    for i in range(n2 + 1):
        x = int(input(f"Enter the coefficient for the exponent {i}\n"))
        poly2.append(x)


    result = addition(poly1, poly2)
    diff = subtraction(poly1, poly2)
    prod =  multiply(poly1, poly2)

    print("The first polynomial is:")
    print_polynomial(poly1)
    
    print("The second polynomial is:")
    print_polynomial(poly2)
    
    print("The result of the addition is:")
    print_polynomial(result)

    print("The result of the Subtraction is:")
    print_polynomial(diff)

    print("The result of the Multiplication is:")
    print_polynomial(prod)

    
    

if __name__ == "__main__":
    main()
