program cx;
var i,n,q,order,l,r,d,BTM:longint;
    trl,trr,trw,trd,trs:array[0..1000000]of int64;

procedure down(t:longint);
begin
  if trd[t]=0 then exit;
  trw[t]:=trw[t]+trd[t]*(trr[t]-trl[t]+1);
  trd[t<<1]:=trd[t<<1]+trd[t];
  trd[t<<1+1]:=trd[t<<1+1]+trd[t];
  trd[t]:=0;
end;

function query(t,l,r:longint):int64;
var mid:longint;
begin
  if (l<=trl[t])and(r>=trr[t]) then
    exit(trw[t]+trd[t]*(trr[t]-trl[t]+1));
  query:=0;
  mid:=(trl[t]+trr[t])>>1;
  down(t);
  if l<=mid then query:=query+query(t<<1,l,r);
  if r>mid then query:=query+query(t<<1+1,l,r);
end;

procedure change(t,l,r,d:longint);
var mid:longint;
begin
  if (l<=trl[t])and(r>=trr[t]) then
    begin trd[t]:=trd[t]+d; exit end;
  mid :=(trl[t]+trr[t])>>1;
  down(t);
  if l<=mid then change(t<<1,l,r,d);
  if r>mid then change(t<<1+1,l,r,d);
  trw[t]:=trw[t<<1]+trw[t<<1+1]+
          trd[t<<1]*(trr[t<<1]-trl[t<<1]+1)+
          trd[t<<1+1]*(trr[t<<1+1]-trl[t<<1+1]+1);
end;

begin
  read(n);
  BTM:=1;
  while BTM<n do BTM:=BTM<<1;
  dec(BTM);
  for i:=1 to n do
    begin
      read(trw[i+BTM]);
      trl[i+BTM]:=i;
      trr[i+BTM]:=i;
      trs[i+BTM]:=1;
    end;
  for i:=n+1 to BTM+1 do
    begin
      trl[i+BTM]:=i;
      trr[i+BTM]:=i;
      trs[i+BTM]:=1;
    end;
  for i:=BTM downto 1 do
    begin
      trl[i]:=trl[i<<1];
      trr[i]:=trr[(i<<1) xor 1];
      trw[i]:=trw[i<<1]+trw[(i<<1) xor 1];
      trs[i]:=trs[i<<1]<<1;
    end;

  read(q);
  for i:=1 to q do
    begin
      read(order);
      if order=1 then
        begin
          read(l,r,d);
          change(1,l,r,d);
        end
        else begin
               read(l,r);
               writeln(query(1,l,r));
             end;
    end;
end.