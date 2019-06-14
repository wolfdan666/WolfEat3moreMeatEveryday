// 2019年6月14日18:13:16 开始看E题
// 其实答案没有看懂,所以pass先把
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
// Constants
typedef long long int lld;
const lld R = 1000 * 1000 * 1000 + 7; // a^(R-1) = 1 (mod R)
const lld matrixRemainder = R-1;

// Matrix class
class matrix{
public:

    // Attributes
    int row, col;
    vector<vector<lld>> num;

    // Constructor
    matrix(int row, int col, int defaultValue = 0){
        this->num = vector<vector<lld>>(row, vector<lld>(col, defaultValue));
        this->row = row, this->col = col;
    }
    matrix(vector<vector<lld>> num){
        this->num = num;
        this->row = this->num.size();
        this->col = this->num[0].size();
    }

    // Operator
    matrix operator *(matrix &another){
        if(this->col != another.row){
            printf("Wrong size: %d*%d X %d*%d\n", this->row, this->col, another.row, another.col);
            throw "Wrong size";
        }
        matrix newone(this->row, another.col);
        for(int r=0; r<newone.row; r++) for(int c=0; c<newone.col; c++){
            for(int k=0; k<this->col; k++){
                newone.num[r][c] += this->num[r][k] * another.num[k][c];
                newone.num[r][c] %= matrixRemainder;
            }
        } return newone;
    }

    // Power
    matrix operator ^(lld x){
        if(x==0){
            printf("Not implemented yet.\n");
            throw "Not implemented";
        }
        else if(x==1) return *this;
        else{
            matrix halfpower = (*this) ^ (x/2);
            if(x%2 == 0) return halfpower * halfpower;
            else return halfpower * halfpower * (*this);
        }
    }
};

// Prime related
const int limit = 1<<20;
bool isPrime[limit] = {false, };
vector<lld> primes;

// Decomposite given value to primes
vector<lld> primeDecomposition(lld x){
    vector<lld> answer;
    for(lld p: primes){
        if(x <= 1) break;
        else if(x%p == 0){
            answer.push_back(p);
            while(x%p == 0) x /= p;
        }
        else if(p*p > x){
            answer.push_back(x);
            break;
        }
    } return answer;
}

// Return a^x % R
lld power(lld a, lld x){
    if(x==0) return 1;
    lld half = power(a, x/2);
    if(x%2 == 0) return half*half%R;
    else return half*half%R*a%R;
}

// Main function
int main(void){

    // Matrix functionality testing
    //matrix a1({{1, 2}, {0, 1}}), a2({{3, 2}, {-1, 0}});
    //matrix b = a1*a2;
    //printf("a1*a2 = \n  %lld %lld\n  %lld %lld\n", b.num[0][0], b.num[0][1], b.num[1][0], b.num[1][1]);

    // Calculate primes
    for(int i=2; i<limit; i++) isPrime[i] = true;
    for(int i=2; i<limit; i++) if(isPrime[i]){
        primes.push_back((lld)i);
        for(int j=2*i; j<limit; j+=i) isPrime[j] = false;
    }

    // Get input
    lld n, f[4], c; scanf("%lld %lld %lld %lld %lld", &n, &f[1], &f[2], &f[3], &c);
    matrix baseLogPropagate({{1, 1, 1}, {1, 0, 0}, {0, 1, 0}});
    matrix totalLogPropagate = baseLogPropagate ^ (n-3);

    // Calculate target primes
    set<lld> knownprimes;
    for(int i=1; i<=3; i++) for(lld p: primeDecomposition(f[i])) knownprimes.insert(p);
    for(lld p: primeDecomposition(c)) knownprimes.insert(p);
    //printf("Known primes: "); for(lld knownprime: knownprimes) printf("%lld, ", knownprime); printf("\n");

    // Calculate c^n * f[n]'s prime count: initPrimeCount[x]: f[3-x]'s p-occurrence
    map<lld, lld> fnPrimeCount;
    for(lld p: knownprimes){
        matrix initPrimeCount(3, 1);
        for(int i=1; i<=3; i++){
            for(lld num = f[i]; num%p == 0; num /= p) initPrimeCount.num[3-i][0]++; // f[n]
            for(lld num = c; num%p == 0; num /= p) initPrimeCount.num[3-i][0] += i; // c^n
        }
        matrix lastPrimeCount = totalLogPropagate * initPrimeCount;
        fnPrimeCount[p] = lastPrimeCount.num[0][0];
    }

    // Calculate answer = product(p^fnPrimeCount[p]) * c^(-n)
    lld answer = 1;
    for(auto pinfo: fnPrimeCount){
        //printf("%lld-occurrence = %lld\n", pinfo.first, pinfo.second);
        answer *= power(pinfo.first, pinfo.second);
        answer %= R;
    }
    answer *= power(power(c, R-2), n); answer %= R;
    printf("%lld\n", answer);
    return 0;
}