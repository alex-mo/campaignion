(function($) {

Drupal.behaviors.email_to_target_selector = {
  attach: function(context) {
    $('.email-to-target-selector-wrapper', context).each(function() {
      $('.email-to-target-target', this).each(function() {
        var $send = $('.form-type-checkbox', this).first();
        var $siblings = $send.siblings();
        var editable = $('.form-type-textarea.form-disabled', this).length <= 0;
        var link_text = editable ? Drupal.t('personalise this email') : Drupal.t('review message');
        var $edit = $('<span class="email-to-target-edit"><a href="#">' + link_text + '</a></span>');
        $siblings.hide();
        var visible = false;

        $('input[type=checkbox]', $send).change(function(event) {
          if ($(this).is(':checked')) {
            $edit.show();
            if (visible) {
              $siblings.show();
            }
          }
          else {
            $edit.hide();
            $siblings.hide();
          }
        }).trigger('change');

        $edit.appendTo($send.find('label')).click(function(event) {
          visible = !visible;
          if (visible) {
            $siblings.show();
          }
          else {
            $siblings.hide();
          }
          event.preventDefault();
        });
      });
    });
  },
};

})(jQuery);
