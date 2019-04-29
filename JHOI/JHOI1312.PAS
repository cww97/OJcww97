program cx;
uses math;
var i,n,ans,j:longint;
    ff:array[0..300,0..300]of longint;
    a:array[0..300]of longint;

function f(l,r:longint):longint;
var i,hk:longint;
begin
  if l=r then exit(0);
  if ff[l,r]<>0 then exit(ff[l,r]);
  hk:=0;
  for i:=l to r-1 do hk:=max(hk,f(l,i)+f(i+1,r)+a[l]*a[i+1]*a[r+1]);
 // hk:=hk+a[l]*a[i+1]*a[r+1];
  ff[l,r]:=hk;
  exit(hk);
end;

begin
  read(n);
  for i:=1 to n do
    begin read(a[i]); a[n+i]:=a[i] end;
  a[0]:=a[n]; a[n<<1+1]:=a[1];
  ans:=0;
  for i:=1 to n do ans:=max(f(i,n+i-1),ans);
  for i:=1 to n<<1 do
    begin
      for j:=1 to n<<1 do write(ff[i,j]:5);
      writeln;
    end;
  writeln(ans);
end.
