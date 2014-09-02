import eviluni

t = eviluni.UnicodeEvilnessTester()

print('Foo', t.test('Foo'))
print('hi', t.test('hi'))
print('ａｒｆ', t.test('ａｒｆ'))
print('arｆ', t.test('arｆ'))
print('сake', t.test('сake'))
print('cake', t.test('cake'))
