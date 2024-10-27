// Chức năng thích bài đăng
function likePost(btn) {
    btn.innerHTML = "Đã thích";
    btn.disabled = true;
}

// Hiển thị/ẩn phần bình luận
function showComments(btn) {
    var commentsSection = btn.nextElementSibling;
    if (commentsSection.style.display === "none") {
        commentsSection.style.display = "block";
    } else {
        commentsSection.style.display = "none";
    }
}

// Thêm bình luận mới
function addComment(btn) {
    var input = btn.previousElementSibling;
    var commentText = input.value;
    if (commentText.trim() === "") return;

    var commentsContainer = btn.nextElementSibling;
    var commentElement = document.createElement("div");
    commentElement.classList.add("comment");
    commentElement.textContent = commentText;
    commentsContainer.appendChild(commentElement);

    input.value = "";
}

// ... Các chức năng xử lý sự kiện và các phần khác giữ nguyên từ mẫu trước ...

// Thêm bài viết mới
function addPost() {
    var postContent = document.getElementById("post-content").value;
    if (postContent.trim() === "") return;

    var postContainer = document.querySelector(".post-container");
    var postElement = document.createElement("div");
    postElement.classList.add("post");

    var userElement = document.createElement("div");
    userElement.classList.add("user-info");
    userElement.innerHTML = `
        <img class="avatar" src="user_avatar.jpg" alt="Avatar">
        <h2>Người dùng 1</h2>
    `;
    postElement.appendChild(userElement);

    var postContentElement = document.createElement("p");
    postContentElement.textContent = postContent;
    postElement.appendChild(postContentElement);

    var interactionsElement = document.createElement("div");
    interactionsElement.classList.add("interactions");
    interactionsElement.innerHTML = `
        <button class="like-btn" onclick="likePost(this)">Thích</button>
        <button class="comment-btn" onclick="showComments(this)">Bình luận</button>
    `;
    postElement.appendChild(interactionsElement);

    var commentsSectionElement = document.createElement("div");
    commentsSectionElement.classList.add("comments-section");
    commentsSectionElement.style.display = "none";
    commentsSectionElement.innerHTML = `
        <input type="text" placeholder="Nhập bình luận">
        <button class="add-comment-btn" onclick="addComment(this)">Bình luận</button>
        <div class="comments">
            <!-- Bình luận sẽ được hiển thị ở đây -->
        </div>
    `;
    postElement.appendChild(commentsSectionElement);

    postContainer.appendChild(postElement);

    document.getElementById("post-content").value = "";
}


// ... Các chức năng xử lý sự kiện và các phần khác giữ nguyên từ mẫu trước ...

// Xử lý đăng nhập
function login() {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    // Xử lý logic đăng nhập ở đây (kiểm tra tên người dùng và mật khẩu)

    // Ví dụ đơn giản: Nếu người dùng nhập "admin" làm tên người dùng và "password" làm mật khẩu thì cho phép đăng nhập thành công
    if (username === "admin" && password === "password") {
        alert("Đăng nhập thành công!");
        // Chuyển hướng đến trang đăng bài viết
        document.querySelector(".login-form").style.display = "none";
        document.querySelector(".post-container").style.display = "block";
        return false; // Ngăn form submit
    } else {
        alert("Tên người dùng hoặc mật khẩu không chính xác.");
        return false; // Ngăn form submit
    }
}
