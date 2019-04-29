program cx;
var i,m,n,hk:longint;
    a:array[0..100000]of longint;
    v:array[0..100000]of boolean;
    ok:boolean;

procedure dfs(k:longint);
var i:longint;
begin
  if ok then exit;
  if k=n+1 then
    begin
      inc(hk);
      if hk=m then ok:=true;
      exit;
    end;
  for i:=1 to n do
    begin
      if ok then exit;
      if not v[i] then
        begin
          v[i]:=true;
          a[k]:=i;
          dfs(k+1);
          v[i]:=false;
        end;
    end;
end;

begin
  read(n,m);
  dfs(1);
  for i:=1 to n do write(a[i],' ');
  writeln;
end.
