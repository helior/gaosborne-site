$(function(){
  var Osborne = Osborne || {};
  
  Osborne.storeNavigation = $('#store-navigation');
  /* Initiate Superfish in navigation
   * REMOVE SLASH TO DISABLE --> */
  Osborne.storeNavigation.children('> ul').superfish({
    dropshadows: false,
    autoArrows: false,
    delay: 0,
    pathLevels: 0,
    onInit: function() {
      $(this).find('li li ul').remove();
    },
    onBeforeShow: function() {
      $(this).siblings('.image').removeClass('hidden').stop().fadeTo(200, 1);
    },
    
    onHide: function(){
      $(this).siblings('.image').addClass('hidden').stop().css({opacity:0});
    }
  });
  //*/
  
   
  /* Fade in/out sub navigation images
   * --Deferrable--
   * REMOVE SLASH TO DISABLE --> */
  $('li li a', Osborne.storeNavigation).hover(function(e){
      $(e.target).next('.image').removeClass('hidden').stop().fadeTo(200, 1);
  },function(e){
    $(e.target).next('.image').stop().fadeTo(200, 0, function () {
      $(this).addClass('hidden');
    });
  });
  //*/
  
}); //document.ready