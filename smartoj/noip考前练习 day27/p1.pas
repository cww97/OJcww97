program cx;
var a,b:array[1..15,1..10000]of longint;
    i,ii,j,k,n,m,max,win,t:longint;
    money:array[1..15]of longint;

begin

  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to 3 do read(a[i,j]);
      a[i,4]:=0;
    end;
  readln(m);

  for k:=1 to m do
    begin
      for i:=1 to n do
        for j:=1 to 7 do read(b[i,j]);
      readln(win);

      for i:=1 to n do
        for j:=2 to 4 do
          inc(a[i,4],a[i,j]*b[i,j]);           {zhu shu ju}

      max:=0;
      for i:=1 to n do
        if a[i,4]>max then begin max:=a[i,4]; ii:=i; end;

      if win=0 then             {mvp}
        begin
          for i:=n downto 1 do dec(a[i,4],200);
          inc(a[ii,4],200);
        end
      else
        begin
          inc(a[ii,4],20);         //mvp

          max:=0;
          for i:=n to 1 do           {fuhao}
            begin
              money[i]:=b[i,6]*40+b[i,2]*250-b[i,3]*100+b[i,5]*450;
              if money[i]>max then
                begin max:=money[i]; ii:=i; end;
            end;
          inc(a[ii,4],10);             //fuhao
        end;

      for t:=4 to 5 do
        begin
          max:=0;                         {pojun,pianjiang}
          for i:=n to 1 do
          if b[i,t]>max then begin max:=b[i,t]; ii:=i; end;
          inc(a[ii,4],10);
        end;

      max:=0;                         {bu  wang}
      for i:=n downto 1 do
      if b[i,t]>max then begin max:=b[i,t]; ii:=i; end;
      inc(a[ii,4],10);
    end;

  for i:=1 to n do
    begin
      a[i,4]:=a[i,4] div m;
      inc(a[i,4],1200);
    end;

  for i:=1 to n do writeln(a[i,4]);
end.