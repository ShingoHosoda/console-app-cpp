-- Webアプリケーションに向けてのSQLコード
-- createdb-17 todo
-- psql-17 todo
-- PostgreSQL16 and 17で動作確認済み
-- テーブルの作成
CREATE TABLE todo(
  id UUID PRIMARY KEY DEFAULT gen_random_uuid() NOT NULL,
  title VARCHAR(255) NOT NULL,
  duedate DATE NOT NULL,
  completed BOOLEAN NOT NULL
);
-- 基本的なCRUDのSQLコード
-- Create
INSERT INTO todo(title, duedate, completed) VALUES('タイトル01', '2025-03-01', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル02', '2025-03-15', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル03', '2025-03-31', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル04', '2025-03-15', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル05', '2025-03-01', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル06', '2025-03-01', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル07', '2025-03-15', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル08', '2025-03-31', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル09', '2025-03-15', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル10', '2025-03-01', FALSE);
INSERT INTO todo(title, duedate, completed) VALUES('タイトル11', '2025-03-01', FALSE);
-- Read
SELECT * FROM todo;
-- Update
UPDATE todo SET completed = TRUE WHERE id = '7ac91684-9ee0-4877-9921-d0c281c7aead';
-- Delete
DELETE FROM todo WHERE id = '94bf5f2b-6fa4-493e-92c8-03230fa6e534';
-- Sort
-- タイトルを基準に昇順と降順
SELECT * FROM todo ORDER BY title ASC;
SELECT * FROM todo ORDER BY title DESC;
-- 期限日を基準に昇順と降順
SELECT * FROM todo ORDER BY duedate ASC;
SELECT * FROM todo ORDER BY duedate DESC;
-- 完了かどうかを基準に昇順と降順
SELECT * FROM todo ORDER BY completed ASC;
SELECT * FROM todo ORDER BY completed DESC;
-- Search
-- 完了しているかどうかで検索
SELECT * FROM todo WHERE completed = TRUE;
SELECT * FROM todo WHERE completed = FALSE;
-- 特定の文字列が含まれているタイトルを検索
SELECT * FROM todo WHERE title LIKE 'タイトル0%';