// 2019年4月15日23:06:49开始看题
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <map>
#include <sstream>
#include <climits>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long

/*
                                       .....'',;;::cccllllllllllllcccc:::;;,,,''...'',,'..
                            ..';cldkO00KXNNNNXXXKK000OOkkkkkxxxxxddoooddddddxxxxkkkkOO0XXKx:.
                      .':ok0KXXXNXK0kxolc:;;,,,,,,,,,,,;;,,,''''''',,''..              .'lOXKd'
                 .,lx00Oxl:,'............''''''...................    ...,;;'.             .oKXd.
              .ckKKkc'...'',:::;,'.........'',;;::::;,'..........'',;;;,'.. .';;'.           'kNKc.
           .:kXXk:.    ..       ..................          .............,:c:'...;:'.         .dNNx.
          :0NKd,          .....''',,,,''..               ',...........',,,'',,::,...,,.        .dNNx.
         .xXd.         .:;'..         ..,'             .;,.               ...,,'';;'. ...       .oNNo
         .0K.         .;.              ;'              ';                      .'...'.           .oXX:
        .oNO.         .                 ,.              .     ..',::ccc:;,..     ..                lXX:
       .dNX:               ......       ;.                'cxOKK0OXWWWWWWWNX0kc.                    :KXd.
     .l0N0;             ;d0KKKKKXK0ko:...              .l0X0xc,...lXWWWWWWWWKO0Kx'                   ,ONKo.
   .lKNKl...'......'. .dXWN0kkk0NWWWWWN0o.            :KN0;.  .,cokXWWNNNNWNKkxONK: .,:c:.      .';;;;:lk0XXx;
  :KN0l';ll:'.         .,:lodxxkO00KXNWWWX000k.       oXNx;:okKX0kdl:::;'',;coxkkd, ...'. ...'''.......',:lxKO:.
 oNNk,;c,'',.                      ...;xNNOc,.         ,d0X0xc,.     .dOd,           ..;dOKXK00000Ox:.   ..''dKO,
'KW0,:,.,:..,oxkkkdl;'.                'KK'              ..           .dXX0o:'....,:oOXNN0d;.'. ..,lOKd.   .. ;KXl.
;XNd,;  ;. l00kxoooxKXKx:..ld:         ;KK'                             .:dkO000000Okxl;.   c0;      :KK;   .  ;XXc
'XXdc.  :. ..    '' 'kNNNKKKk,      .,dKNO.                                   ....       .'c0NO'      :X0.  ,.  xN0.
.kNOc'  ,.      .00. ..''...      .l0X0d;.             'dOkxo;...                    .;okKXK0KNXx;.   .0X:  ,.  lNX'
 ,KKdl  .c,    .dNK,            .;xXWKc.                .;:coOXO,,'.......       .,lx0XXOo;...oNWNXKk:.'KX;  '   dNX.
  :XXkc'....  .dNWXl        .';l0NXNKl.          ,lxkkkxo' .cK0.          ..;lx0XNX0xc.     ,0Nx'.','.kXo  .,  ,KNx.
   cXXd,,;:, .oXWNNKo'    .'..  .'.'dKk;        .cooollox;.xXXl     ..,cdOKXXX00NXc.      'oKWK'     ;k:  .l. ,0Nk.
    cXNx.  . ,KWX0NNNXOl'.           .o0Ooldk;            .:c;.':lxOKKK0xo:,.. ;XX:   .,lOXWWXd.      . .':,.lKXd.
     lXNo    cXWWWXooNWNXKko;'..       .lk0x;       ...,:ldk0KXNNOo:,..       ,OWNOxO0KXXNWNO,        ....'l0Xk,
     .dNK.   oNWWNo.cXK;;oOXNNXK0kxdolllllooooddxk00KKKK0kdoc:c0No        .'ckXWWWNXkc,;kNKl.          .,kXXk,
      'KXc  .dNWWX;.xNk.  .kNO::lodxkOXWN0OkxdlcxNKl,..        oN0'..,:ox0XNWWNNWXo.  ,ONO'           .o0Xk;
      .ONo    oNWWN0xXWK, .oNKc       .ONx.      ;X0.          .:XNKKNNWWWWNKkl;kNk. .cKXo.           .ON0;
      .xNd   cNWWWWWWWWKOkKNXxl:,'...;0Xo'.....'lXK;...',:lxk0KNWWWWNNKOd:..   lXKclON0:            .xNk.
      .dXd   ;XWWWWWWWWWWWWWWWWWWNNNNNWWNNNNNNNNNWWNNNNNNWWWWWNXKNNk;..        .dNWWXd.             cXO.
      .xXo   .ONWNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNK0ko:'..OXo          'l0NXx,              :KK,
      .OXc    :XNk0NWXKNWWWWWWWWWWWWWWWWWWWWWNNNX00NNx:'..       lXKc.     'lONN0l.              .oXK:
      .KX;    .dNKoON0;lXNkcld0NXo::cd0NNO:;,,'.. .0Xc            lXXo..'l0NNKd,.              .c0Nk,
      :XK.     .xNX0NKc.cXXl  ;KXl    .dN0.       .0No            .xNXOKNXOo,.               .l0Xk;.
     .dXk.      .lKWN0d::OWK;  lXXc    .OX:       .ONx.     . .,cdk0XNXOd;.   .'''....;c:'..;xKXx,
     .0No         .:dOKNNNWNKOxkXWXo:,,;ONk;,,,,,;c0NXOxxkO0XXNXKOdc,.  ..;::,...;lol;..:xKXOl.
     ,XX:             ..';cldxkOO0KKKXXXXXXXXXXKKKKK00Okxdol:;'..   .';::,..':llc,..'lkKXkc.
     :NX'    .     ''            ..................             .,;:;,',;ccc;'..'lkKX0d;.
     lNK.   .;      ,lc,.         ................        ..,,;;;;;;:::,....,lkKX0d:.
    .oN0.    .'.      .;ccc;,'....              ....'',;;;;;;;;;;'..   .;oOXX0d:.
    .dN0.      .;;,..       ....                ..''''''''....     .:dOKKko;.
     lNK'         ..,;::;;,'.........................           .;d0X0kc'.
     .xXO'                                                 .;oOK0x:.
      .cKKo.                                    .,:oxkkkxk0K0xc'.
        .oKKkc,.                         .';cok0XNNNX0Oxoc,.
          .;d0XX0kdlc:;,,,',,,;;:clodkO0KK0Okdl:,'..
              .,coxO0KXXXXXXXKK0OOxdoc:,..
                        ...

*/

#define N 500004
#define M 3004
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define fornr(i, n) for (int i = int(n)-1; i >= 0; i--)


ll n;


ll ar[N];



int main() {
    std::ios_base::sync_with_stdio(false);
    ll l=0, r=0;
    cin >> n;
    forn(i, n) {
        cin >> ar[i];
        if (ar[i])l++;
        else r++;
    }
    forn(i, n) {
        if (ar[i])l--;
        else r--;
        if (l == 0 || r == 0)return cout << i + 1, 0;
    }
    return 0;
}