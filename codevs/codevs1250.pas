program cx;
type matrix=array[1..2,1..2]of longint;
const gym:matrix=((1,1),
                  (1,0));
var i,n,t,q:longint;
    ans:matrix;

function mc(x,y:matrix):matrix;
var lj:matrix;
begin
  lj[1,1]:=(x[1,1]*y[1,1]+x[1,2]*y[2,1])mod q;
  lj[1,2]:=(x[1,1]*y[1,2]+x[1,2]*y[2,2])mod q;
  lj[2,1]:=(x[2,1]*y[1,1]+x[2,2]*y[2,1])mod q;
  lj[2,2]:=(x[2,1]*y[1,2]+x[2,2]*y[2,2])mod q;
  exit(lj);
end;

function power(hk:matrix;x:longint):matrix;
var temp:matrix;
begin
  if x=1 then exit(hk);
  temp:=power(hk,x>>1);
  temp:=mc(temp,temp);
  if x and 1=1 then temp:=mc(temp,hk);
  exit(temp);
end;

begin
  read(t);
  for i:=1 to t do
    begin
      read(n,q);
      ans:=power(gym,n);
      writeln(ans[1,1] mod q);
    end;
end.
