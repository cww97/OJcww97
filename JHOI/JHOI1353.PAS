program cx;
type matrix:array[1..2,1..2]of longint;
const hk:matrix=((1,1),
                 (1,0));
var i,n,m:longint;
    fi:array[0..1000000]of longint;

function mc(x,y:matrix):matrix;
var i:longint;
    so:matrix;
begin
  so[1,1]:=x[1,1]*y[1,1]+x[1,2]*y[2,1];
  so[1,2]:=x[1,1]*y[1,2]+x[1,2]*y[2,2];
  so[2,1]:=x[2,1]*y[1,1]+x[2,2]+y[2,1];
  so[2,2]:=x[2,1]*y[2,1]+x[2,2]+y[2,2];
  exit(so);
end;

function power(ma:matrix,x:longint)matrix;
var i:longint;
    temp:matrix;
begin
  if x=1 then exit(hk);
  temp:=power(ma,x>>1);
  temp:=mc(temp,temp);
  if x and 1=1 then temp:=mc(temp,ma);
  exit(temp); 
end;

function fib(x:longint):longint;
var i:longint;
    a:matrix;
begin
  if (x=0) or (x=1) then exit(1);
  a:=power(hk,x);
  exit(a[1,1]);
end;

begin
  fillchar(prime,sizeof(prime),1);
  prime[1]:=false;
  prime[2]:=true;
  for i:=2 to 1000000 do
    begin
      if prime[i] then 
        begin
          for j:=2 to 100000 do
            begin
              prime[j*i]:=false;
              if i*j>1000000 then break;
            end;
        end;
    end;
  

  read(m);
  fillchar(fi,sizeof(fi),0);
  for i:=1 to m do
    begin
      read(n);
      if prime[fib(n-1)] then writeln('true')
        else writeln('false');
    end;
end.
