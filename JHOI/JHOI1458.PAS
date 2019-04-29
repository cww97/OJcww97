program cx;
var i,x,y,n,top,hk,k:longint;
    g,gg:array[0..100,0..100]of longint;
    a,tr:array[0..1000]of longint;
    v:array[0..1000]of boolean;

function dfs(p:longint):boolean;
var i:longint;
begin
  v[p]:=true;
  if k>n div 2 then exit(false);
  for i:=1 to n do
    begin
      if v[i] then continue;
      if gg[p,i]=1 then
        begin
          v[i]:=true;
          inc(k);
          if not dfs(i) then exit(false);
        end;
    end;
  exit(true);
end;

function check(x:longint):boolean;
var i:longint;
begin
  hk:=0;
  fillchar(v,sizeof(v),0);
  v[x]:=true;
  for i:=1 to n do
    begin
      if gg[x,i]=1 then
        begin
          gg[x,i]:=0;
          gg[i,x]:=0;
          inc(hk);
          tr[hk]:=i;
        end;
    end;

  for i:=1 to hk do
    begin
      k:=1;
      if not dfs(tr[i]) then exit(false);
    end;
  exit(true);
end;

begin
  assign(input, 'hk.in'); reset(input);
  //assign(output,'hk.out');rewrite(output);
  read(n);
  for i:=1 to n-1 do
    begin
      read(x,y);
      g[x,y]:=1;
      g[y,x]:=1;
    end;
  for i:=1 to n do
    begin
      gg:=g;
      if check(i) then
        begin inc(top); a[top]:=i; end;
    end;
  for i:=1 to top do writeln(a[i]);
  if top=0 then writeln('NONE');
  close(input);
  //close(output);
end.
