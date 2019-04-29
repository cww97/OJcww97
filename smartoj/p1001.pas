program cx;
var i,t,kong:longint;
    st,st1,st2:ansistring;
    a,b,c:array[0..1007] of longint;

function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;

begin
  readln(st);
  kong:=pos(' ',st);
  st1:=copy(st,1,kong-1);
  st2:=copy(st,kong+1,length(st)-kong);
  a[0]:=length(st1);
  for i:=1 to a[0] do val(st1[a[0]-i+1],a[i]);
  b[0]:=length(st2);
  for i:=1 to b[0] do val(st2[b[0]-i+1],b[i]);
  c[0]:=max(a[0],b[0]);

  for i:=1 to c[0] do
    begin
      t:=a[i]+b[i]+c[i];
      c[i]:=t mod 10;
      c[i+1]:=c[i+1]+t div 10;
    end;
  if c[c[0]+1]<>0 then inc(c[0]);
  for i:=c[0] downto 1 do write(c[i]);
  writeln;
end.
