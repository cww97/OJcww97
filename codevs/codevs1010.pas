program cx;
var i,n,m,x,y:longint;
    f:array[0..20,0..20]of longint;
    ho:array[0..20,0..20]of boolean;

function find(x,y:longint):longint;
begin
  if (x<0)or(y<0) then exit(0);
  if ho[x,y] then exit(0);
  if f[x,y]<>0 then exit(f[x,y]);
  f[x,y]:=find(x-1,y)+find(x,y-1);
  exit(f[x,y]);
end;

begin
  read(n,m,x,y);
  ho[x,y]:=true;
  ho[x+1,y+2]:=true; ho[x+1,y-2]:=true;
  ho[x-1,y+2]:=true; ho[x-1,y-2]:=true;
  ho[x+2,y+1]:=true; ho[x+2,y-1]:=true;
  ho[x-2,y+1]:=true; ho[x-2,y-1]:=true;
  f[0,0]:=1;
  writeln(find(n,m));
end.
