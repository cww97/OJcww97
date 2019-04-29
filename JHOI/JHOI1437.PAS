program cx;
uses math;
var i,n:longint;
    a,s:array[0..10007]of longint;
    hk:array[0..5000,0..5000]of longint;

function find(l,r:longint):longint;
var i,temp:longint;
begin
  if hk[l,r]<>0 then exit(hk[l,r]);
  if l=r then exit(0);
  temp:=maxlongint;
  for i:=l to r-1 do
    begin
      temp:=min(temp,find(l,i)+find(i+1,r));
    end;
  hk[l,r]:=temp+s[r]-s[l-1];
  exit(hk[l,r]);
end;

begin
  read(n);
  for i:=1 to n do
    begin
      read(a[i]);
      s[i]:=s[i-1]+a[i];
    end;
  writeln(find(1,n));
end.
