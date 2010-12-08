$(function(){
  $('#add-review').click(function(e) {
    var $form = $('#comment-form');
    
    $(this).slideUp('fast', function() {
      $form.slideDown('normal', function(){
        $('input:first', $form).focus();
      });
    });
    
    e.preventDefault();
  })
})