program cx;
var i,j,n:longint;
    a,b,c:array[0..100000]of longint;

function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;

begin
  read(n);
  a[0]:=1;
  a[1]:=1;
  b[0]:=1;
  b[1]:=1;
  for i:=1 to n-2 do
    begin
      fillchar(c,sizeof(c),0);
      c[0]:=max(a[0],b[0]);
      for j:=1 to c[0] do
        begin
          c[j]:=c[j]+(a[j]+b[j])mod 10;
          c[j+1]:=(a[j]+b[j])div 10;
        end;
      if c[c[0]+1]>0 then inc(c[0]);
      a:=b;
      b:=c;
    end;
  if n<=2 then writeln(1)
    else
      begin
        for i:=c[0] downto 1 do write(c[i]);
        writeln;
      end;
end.
