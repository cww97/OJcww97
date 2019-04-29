program cx;
var i,j,n:longint;
    r,br,abr,cr:array[0..507]of longint;
    a,b,c:array[0..507,0..507]of longint;
    ok:boolean;

begin
  read(n);
  for i:=1 to n do 
    for j:=1 to n do read(a[i,j]);
  for i:=1 to n do 
    for j:=1 to n do read(b[i,j]);
  for i:=1 to n do 
    for j:=1 to n do read(c[i,j]);

  randomize;
  for i:=1 to n do r[i]:=random(99)+1;
  
  ok:=true;
  for i:=1 to n do
    for j:=1 to n do br[i]:=br[i]+b[i,j]*r[j];
  for i:=1 to n do
    for j:=1 to n do abr[i]:=abr[i]+a[i,j]*br[j];
  for i:=1 to n do
    for j:=1 to n do cr[i]:=cr[i]+c[i,j]*r[j];
  for i:=1 to n do 
    if abr[i]<>cr[i] then ok:=false;
  if ok then writeln('YES')
    else writeln('NO');
end.